#include "CHidKeyUtils.h"
#include <windows.h>

typedef struct _HID_SCAN_INFO
{
    _tstring strName;       // 按键名
    uint8_t nUsageID;       // HID 用法 ID
    uint16_t nScanCode;     // 扫描码

    _HID_SCAN_INFO(_tstring _name, uint8_t _id, uint16_t _sc) :strName(_name), nUsageID(_id), nScanCode(_sc)
    {
    }

}HID_SCANCODE_INFO;

#define AddHidKeyboardInfo(_name, _id, _sc)   {_T(_name), HID_SCANCODE_INFO(_T(_name), _id, _sc) }

// https://learn.microsoft.com/zh-cn/windows/win32/inputdev/about-keyboard-input
// https://learn.microsoft.com/en-us/windows/win32/inputdev/about-keyboard-input
std::map<_tstring, HID_SCANCODE_INFO> g_mapHidScanOrigin =      //原始映射表(扫描码查询键名使用)
{
    //AddHidKeyboardInfo("ErrorRollOver",         0x0001, 0x00FF),
    AddHidKeyboardInfo("A",                     0x0004, 0x001E),
    AddHidKeyboardInfo("B",                     0x0005, 0x0030),
    AddHidKeyboardInfo("C",                     0x0006, 0x002E),
    AddHidKeyboardInfo("D",                     0x0007, 0x0020),
    AddHidKeyboardInfo("E",                     0x0008, 0x0012),
    AddHidKeyboardInfo("F",                     0x0009, 0x0021),
    AddHidKeyboardInfo("G",                     0x000A, 0x0022),
    AddHidKeyboardInfo("H",                     0x000B, 0x0023),
    AddHidKeyboardInfo("I",                     0x000C, 0x0017),
    AddHidKeyboardInfo("J",                     0x000D, 0x0024),
    AddHidKeyboardInfo("K",                     0x000E, 0x0025),
    AddHidKeyboardInfo("L",                     0x000F, 0x0026),
    AddHidKeyboardInfo("M",                     0x0010, 0x0032),
    AddHidKeyboardInfo("N",                     0x0011, 0x0031),
    AddHidKeyboardInfo("O",                     0x0012, 0x0018),
    AddHidKeyboardInfo("P",                     0x0013, 0x0019),
    AddHidKeyboardInfo("Q",                     0x0014, 0x0010),
    AddHidKeyboardInfo("R",                     0x0015, 0x0013),
    AddHidKeyboardInfo("S",                     0x0016, 0x001F),
    AddHidKeyboardInfo("T",                     0x0017, 0x0014),
    AddHidKeyboardInfo("U",                     0x0018, 0x0016),
    AddHidKeyboardInfo("V",                     0x0019, 0x002F),
    AddHidKeyboardInfo("W",                     0x001A, 0x0011),
    AddHidKeyboardInfo("X",                     0x001B, 0x002D),
    AddHidKeyboardInfo("Y",                     0x001C, 0x0015),
    AddHidKeyboardInfo("Z",                     0x001D, 0x002C),
    AddHidKeyboardInfo("1 & !",                 0x001E, 0x0002),
    AddHidKeyboardInfo("2 & @",                 0x001F, 0x0003),
    AddHidKeyboardInfo("3 & #",                 0x0020, 0x0004),
    AddHidKeyboardInfo("4 & $",                 0x0021, 0x0005),
    AddHidKeyboardInfo("5 & %",                 0x0022, 0x0006),
    AddHidKeyboardInfo("6 & ^",                 0x0023, 0x0007),
    AddHidKeyboardInfo("7 & &",                 0x0024, 0x0008),
    AddHidKeyboardInfo("8 & *",                 0x0025, 0x0009),
    AddHidKeyboardInfo("9 & (",                 0x0026, 0x000A),
    AddHidKeyboardInfo("0 & )",                 0x0027, 0x000B),
    AddHidKeyboardInfo("Enter",                 0x0028, 0x001C),
    AddHidKeyboardInfo("Escape",                0x0029, 0x0001),
    AddHidKeyboardInfo("Backspace",             0x002A, 0x000E),
    AddHidKeyboardInfo("Tab",                   0x002B, 0x000F),
    AddHidKeyboardInfo("Space",                 0x002C, 0x0039),
    AddHidKeyboardInfo("- & _",                 0x002D, 0x000C),
    AddHidKeyboardInfo("= & +",                 0x002E, 0x000D),
    AddHidKeyboardInfo("[ & {",                 0x002F, 0x001A),
    AddHidKeyboardInfo("] & }",                 0x0030, 0x001B),
    AddHidKeyboardInfo("\\ & |",                0x0031, 0x002B),
    AddHidKeyboardInfo("; & :",                 0x0033, 0x0027),
    AddHidKeyboardInfo("' & \"",                0x0034, 0x0028),
    AddHidKeyboardInfo("` & ~",                 0x0035, 0x0029),
    AddHidKeyboardInfo(", & <",                 0x0036, 0x0033),
    AddHidKeyboardInfo(". & >",                 0x0037, 0x0034),
    AddHidKeyboardInfo("? & /",                 0x0038, 0x0035),
    AddHidKeyboardInfo("Non-US # & ~",          0x0032, 0x002B),
    AddHidKeyboardInfo("Caps Lock",             0x0039, 0x003A),
    AddHidKeyboardInfo("F1",                    0x003A, 0x003B),
    AddHidKeyboardInfo("F2",                    0x003B, 0x003C),
    AddHidKeyboardInfo("F3",                    0x003C, 0x003D),
    AddHidKeyboardInfo("F4",                    0x003D, 0x003E),
    AddHidKeyboardInfo("F5",                    0x003E, 0x003F),
    AddHidKeyboardInfo("F6",                    0x003F, 0x0040),
    AddHidKeyboardInfo("F7",                    0x0040, 0x0041),
    AddHidKeyboardInfo("F8",                    0x0041, 0x0042),
    AddHidKeyboardInfo("F9",                    0x0042, 0x0043),
    AddHidKeyboardInfo("F10",                   0x0043, 0x0044),
    AddHidKeyboardInfo("F11",                   0x0044, 0x0057),
    AddHidKeyboardInfo("F12",                   0x0045, 0x0058),
    AddHidKeyboardInfo("Print Screen",          0x0046, 0xE037),
    AddHidKeyboardInfo("Sya Req",               0x0046, 0x0054),
    AddHidKeyboardInfo("Scroll Lock",           0x0047, 0x0046),  
    AddHidKeyboardInfo("Pause",                 0x0048, 0x0045),
    AddHidKeyboardInfo("Break",                 0x0048, 0xE046),
    AddHidKeyboardInfo("Insert",                0x0049, 0xE052),
    AddHidKeyboardInfo("Home",                  0x004A, 0xE047),
    AddHidKeyboardInfo("Page Up",               0x004B, 0xE049),
    AddHidKeyboardInfo("Delete",                0x004C, 0xE053),
    AddHidKeyboardInfo("End",                   0x004D, 0xE04F),
    AddHidKeyboardInfo("Page Down",             0x004E, 0xE051),
    AddHidKeyboardInfo("Right Arrow",           0x004F, 0xE04D),
    AddHidKeyboardInfo("Left Arrow",            0x0050, 0xE04B),
    AddHidKeyboardInfo("Down Arrow",            0x0051, 0xE050),
    AddHidKeyboardInfo("Up Arrow",              0x0052, 0xE048),
    AddHidKeyboardInfo("Num Lock",              0x0053, 0xE045),
    AddHidKeyboardInfo("Num /",                 0x0054, 0xE035),
    AddHidKeyboardInfo("Num *",                 0x0055, 0x0037),
    AddHidKeyboardInfo("Num -",                 0x0056, 0x004A),
    AddHidKeyboardInfo("Num +",                 0x0057, 0x004E),
    AddHidKeyboardInfo("Num Enter",             0x0058, 0xE01C),
    AddHidKeyboardInfo("Num 1 & End",           0x0059, 0x004F),
    AddHidKeyboardInfo("Num 2 & Down Arrow",    0x005A, 0x0050),
    AddHidKeyboardInfo("Num 3 & Page Dn",       0x005B, 0x0051),
    AddHidKeyboardInfo("Num 4 & Left Arrow",    0x005C, 0x004B),
    AddHidKeyboardInfo("Num 5",                 0x005D, 0x004C),
    AddHidKeyboardInfo("Num 6 & Right Arrow",   0x005E, 0x004D),
    AddHidKeyboardInfo("Num 7 & Home",          0x005F, 0x0047),
    AddHidKeyboardInfo("Num 8 & Up Arrow",      0x0060, 0x0048),
    AddHidKeyboardInfo("Num 9 & Page Up",       0x0061, 0x0049),
    AddHidKeyboardInfo("Num 0 & Insert",        0x0062, 0x0052),
    AddHidKeyboardInfo("Num . & Delete",        0x0063, 0x0053),

    AddHidKeyboardInfo("Non-US /",              0x0064, 0x0056),
    AddHidKeyboardInfo("Application",           0x0065, 0xE05D),
    AddHidKeyboardInfo("Power",                 0x0066, 0xE05E),
    AddHidKeyboardInfo("Keypad =",              0x0067, 0x0059),
    AddHidKeyboardInfo("F13",                   0x0068, 0x0064),
    AddHidKeyboardInfo("F14",                   0x0069, 0x0065),
    AddHidKeyboardInfo("F15",                   0x006A, 0x0066),
    AddHidKeyboardInfo("F16",                   0x006B, 0x0067),
    AddHidKeyboardInfo("F17",                   0x006C, 0x0068),
    AddHidKeyboardInfo("F18",                   0x006D, 0x0069),
    AddHidKeyboardInfo("F19",                   0x006E, 0x006A),
    AddHidKeyboardInfo("F20",                   0x006F, 0x006B),
    AddHidKeyboardInfo("F21",                   0x0070, 0x006C),
    AddHidKeyboardInfo("F22",                   0x0071, 0x006D),
    AddHidKeyboardInfo("F23",                   0x0072, 0x006E),
    AddHidKeyboardInfo("F24",                   0x0073, 0x0076),
    AddHidKeyboardInfo("Left Ctrl",             0x00E0, 0x001D),
    AddHidKeyboardInfo("Left Shift",            0x00E1, 0x002A),
    AddHidKeyboardInfo("Left Alt",              0x00E2, 0x0038),
    AddHidKeyboardInfo("Left Win",              0x00E3, 0xE05B),
    AddHidKeyboardInfo("Right Ctrl",            0x00E4, 0xE01D),
    AddHidKeyboardInfo("Right Shift ",          0x00E5, 0x0036),
    AddHidKeyboardInfo("Right Alt",             0x00E6, 0xE038),
    AddHidKeyboardInfo("Right Win",             0x00E7, 0xE05C),
};

std::map<_tstring, HID_SCANCODE_INFO> g_mapHidScanCompatible =          // 兼容映射表(键名查询扫描码使用)
{
    //AddHidKeyboardInfo("ErrorRollOver",         0x0001, 0x00FF),
    AddHidKeyboardInfo("A",                     0x0004, 0x001E),
    AddHidKeyboardInfo("B",                     0x0005, 0x0030),
    AddHidKeyboardInfo("C",                     0x0006, 0x002E),
    AddHidKeyboardInfo("D",                     0x0007, 0x0020),
    AddHidKeyboardInfo("E",                     0x0008, 0x0012),
    AddHidKeyboardInfo("F",                     0x0009, 0x0021),
    AddHidKeyboardInfo("G",                     0x000A, 0x0022),
    AddHidKeyboardInfo("H",                     0x000B, 0x0023),
    AddHidKeyboardInfo("I",                     0x000C, 0x0017),
    AddHidKeyboardInfo("J",                     0x000D, 0x0024),
    AddHidKeyboardInfo("K",                     0x000E, 0x0025),
    AddHidKeyboardInfo("L",                     0x000F, 0x0026),
    AddHidKeyboardInfo("M",                     0x0010, 0x0032),
    AddHidKeyboardInfo("N",                     0x0011, 0x0031),
    AddHidKeyboardInfo("O",                     0x0012, 0x0018),
    AddHidKeyboardInfo("P",                     0x0013, 0x0019),
    AddHidKeyboardInfo("Q",                     0x0014, 0x0010),
    AddHidKeyboardInfo("R",                     0x0015, 0x0013),
    AddHidKeyboardInfo("S",                     0x0016, 0x001F),
    AddHidKeyboardInfo("T",                     0x0017, 0x0014),
    AddHidKeyboardInfo("U",                     0x0018, 0x0016),
    AddHidKeyboardInfo("V",                     0x0019, 0x002F),
    AddHidKeyboardInfo("W",                     0x001A, 0x0011),
    AddHidKeyboardInfo("X",                     0x001B, 0x002D),
    AddHidKeyboardInfo("Y",                     0x001C, 0x0015),
    AddHidKeyboardInfo("Z",                     0x001D, 0x002C),
    AddHidKeyboardInfo("1",                     0x001E, 0x0002),
    AddHidKeyboardInfo("2",                     0x001F, 0x0003),
    AddHidKeyboardInfo("3",                     0x0020, 0x0004),
    AddHidKeyboardInfo("4",                     0x0021, 0x0005),
    AddHidKeyboardInfo("5",                     0x0022, 0x0006),
    AddHidKeyboardInfo("6",                     0x0023, 0x0007),
    AddHidKeyboardInfo("7",                     0x0024, 0x0008),
    AddHidKeyboardInfo("8",                     0x0025, 0x0009),
    AddHidKeyboardInfo("9",                     0x0026, 0x000A),
    AddHidKeyboardInfo("0",                     0x0027, 0x000B),
    AddHidKeyboardInfo("!",                     0x001E, 0x0002),
    AddHidKeyboardInfo("@",                     0x001F, 0x0003),
    AddHidKeyboardInfo("#",                     0x0020, 0x0004),
    AddHidKeyboardInfo("$",                     0x0021, 0x0005),
    AddHidKeyboardInfo("%",                     0x0022, 0x0006),
    AddHidKeyboardInfo("^",                     0x0023, 0x0007),
    AddHidKeyboardInfo("&",                     0x0024, 0x0008),
    AddHidKeyboardInfo("*",                     0x0025, 0x0009),
    AddHidKeyboardInfo("(",                     0x0026, 0x000A),
    AddHidKeyboardInfo(")",                     0x0027, 0x000B),
    AddHidKeyboardInfo("Enter",                 0x0028, 0x001C),
    AddHidKeyboardInfo("Escape",                0x0029, 0x0001),
    AddHidKeyboardInfo("Backspace",             0x002A, 0x000E),
    AddHidKeyboardInfo("Tab",                   0x002B, 0x000F),
    AddHidKeyboardInfo("Space",                 0x002C, 0x0039),
    AddHidKeyboardInfo("-",                     0x002D, 0x000C),
    AddHidKeyboardInfo("=",                     0x002E, 0x000D),
    AddHidKeyboardInfo("[",                     0x002F, 0x001A),
    AddHidKeyboardInfo("]",                     0x0030, 0x001B),
    AddHidKeyboardInfo("\\",                    0x0031, 0x002B),
    AddHidKeyboardInfo("Non-US #",              0x0032, 0x002B),
    AddHidKeyboardInfo(";",                     0x0033, 0x0027),
    AddHidKeyboardInfo("'",                     0x0034, 0x0028),
    AddHidKeyboardInfo("`",                     0x0035, 0x0029),
    AddHidKeyboardInfo(",",                     0x0036, 0x0033),
    AddHidKeyboardInfo(".",                     0x0037, 0x0034),
    AddHidKeyboardInfo("?",                     0x0038, 0x0035),
    AddHidKeyboardInfo("_",                     0x002D, 0x000C),
    AddHidKeyboardInfo("+",                     0x002E, 0x000D),
    AddHidKeyboardInfo("{",                     0x002F, 0x001A),
    AddHidKeyboardInfo("}",                     0x0030, 0x001B),
    AddHidKeyboardInfo("|",                     0x0031, 0x002B),
    AddHidKeyboardInfo("Non-US ~",              0x0032, 0x002B),
    AddHidKeyboardInfo(":",                     0x0033, 0x0027),
    AddHidKeyboardInfo("\"",                    0x0034, 0x0028),
    AddHidKeyboardInfo("~",                     0x0035, 0x0029),
    AddHidKeyboardInfo("<",                     0x0036, 0x0033),
    AddHidKeyboardInfo(">",                     0x0037, 0x0034),
    AddHidKeyboardInfo("/",                     0x0038, 0x0035),
    AddHidKeyboardInfo("Caps Lock",             0x0039, 0x003A),
    AddHidKeyboardInfo("F1",                    0x003A, 0x003B),
    AddHidKeyboardInfo("F2",                    0x003B, 0x003C),
    AddHidKeyboardInfo("F3",                    0x003C, 0x003D),
    AddHidKeyboardInfo("F4",                    0x003D, 0x003E),
    AddHidKeyboardInfo("F5",                    0x003E, 0x003F),
    AddHidKeyboardInfo("F6",                    0x003F, 0x0040),
    AddHidKeyboardInfo("F7",                    0x0040, 0x0041),
    AddHidKeyboardInfo("F8",                    0x0041, 0x0042),
    AddHidKeyboardInfo("F9",                    0x0042, 0x0043),
    AddHidKeyboardInfo("F10",                   0x0043, 0x0044),
    AddHidKeyboardInfo("F11",                   0x0044, 0x0057),
    AddHidKeyboardInfo("F12",                   0x0045, 0x0058),
    AddHidKeyboardInfo("Print Screen",          0x0046, 0xE037),
    AddHidKeyboardInfo("Sya Req",               0x0046, 0x0054),
    AddHidKeyboardInfo("Scroll Lock",           0x0047, 0x0046),  
    AddHidKeyboardInfo("Pause",                 0x0048, 0x0045),
    AddHidKeyboardInfo("Break",                 0x0048, 0xE046),
    AddHidKeyboardInfo("Insert",                0x0049, 0xE052),
    AddHidKeyboardInfo("Home",                  0x004A, 0xE047),
    AddHidKeyboardInfo("Page Up",               0x004B, 0xE049),
    AddHidKeyboardInfo("Delete",                0x004C, 0xE053),
    AddHidKeyboardInfo("End",                   0x004D, 0xE04F),
    AddHidKeyboardInfo("Page Down",             0x004E, 0xE051),
    AddHidKeyboardInfo("Right Arrow",           0x004F, 0xE04D),
    AddHidKeyboardInfo("Left Arrow",            0x0050, 0xE04B),
    AddHidKeyboardInfo("Down Arrow",            0x0051, 0xE050),
    AddHidKeyboardInfo("Up Arrow",              0x0052, 0xE048),
    AddHidKeyboardInfo("Num Lock",              0x0053, 0xE045),
    AddHidKeyboardInfo("Num /",                 0x0054, 0xE035),
    AddHidKeyboardInfo("Num *",                 0x0055, 0x0037),
    AddHidKeyboardInfo("Num -",                 0x0056, 0x004A),
    AddHidKeyboardInfo("Num +",                 0x0057, 0x004E),
    AddHidKeyboardInfo("Num Enter",             0x0058, 0xE01C),
    AddHidKeyboardInfo("Num 1",                 0x0059, 0x004F),
    AddHidKeyboardInfo("Num 2",                 0x005A, 0x0050),
    AddHidKeyboardInfo("Num 3",                 0x005B, 0x0051),
    AddHidKeyboardInfo("Num 4",                 0x005C, 0x004B),
    AddHidKeyboardInfo("Num 5",                 0x005D, 0x004C),
    AddHidKeyboardInfo("Num 6",                 0x005E, 0x004D),
    AddHidKeyboardInfo("Num 7",                 0x005F, 0x0047),
    AddHidKeyboardInfo("Num 8",                 0x0060, 0x0048),
    AddHidKeyboardInfo("Num 9",                 0x0061, 0x0049),
    AddHidKeyboardInfo("Num 0",                 0x0062, 0x0052),
    AddHidKeyboardInfo("Num .",                 0x0063, 0x0053),
    AddHidKeyboardInfo("Num End",               0x0059, 0x004F),
    AddHidKeyboardInfo("Num Down Arrow",        0x005A, 0x0050),
    AddHidKeyboardInfo("Num Page Dn",           0x005B, 0x0051),
    AddHidKeyboardInfo("Num Left Arrow",        0x005C, 0x004B),
    AddHidKeyboardInfo("Num Right Arrow",       0x005E, 0x004D),
    AddHidKeyboardInfo("Num Home",              0x005F, 0x0047),
    AddHidKeyboardInfo("Num Up Arrow",          0x0060, 0x0048),
    AddHidKeyboardInfo("Num Page Up",           0x0061, 0x0049),
    AddHidKeyboardInfo("Num Insert",            0x0062, 0x0052),
    AddHidKeyboardInfo("Num Delete",            0x0063, 0x0053),
    AddHidKeyboardInfo("Non-US /",              0x0064, 0x0056),
    AddHidKeyboardInfo("Application",           0x0065, 0xE05D),
    AddHidKeyboardInfo("Power",                 0x0066, 0xE05E),
    AddHidKeyboardInfo("Keypad =",              0x0067, 0x0059),
    AddHidKeyboardInfo("F13",                   0x0068, 0x0064),
    AddHidKeyboardInfo("F14",                   0x0069, 0x0065),
    AddHidKeyboardInfo("F15",                   0x006A, 0x0066),
    AddHidKeyboardInfo("F16",                   0x006B, 0x0067),
    AddHidKeyboardInfo("F17",                   0x006C, 0x0068),
    AddHidKeyboardInfo("F18",                   0x006D, 0x0069),
    AddHidKeyboardInfo("F19",                   0x006E, 0x006A),
    AddHidKeyboardInfo("F20",                   0x006F, 0x006B),
    AddHidKeyboardInfo("F21",                   0x0070, 0x006C),
    AddHidKeyboardInfo("F22",                   0x0071, 0x006D),
    AddHidKeyboardInfo("F23",                   0x0072, 0x006E),
    AddHidKeyboardInfo("F24",                   0x0073, 0x0076),
    
    AddHidKeyboardInfo("Left Ctrl",             0x00E0, 0x001D),
    AddHidKeyboardInfo("Left Shift",            0x00E1, 0x002A),
    AddHidKeyboardInfo("Left Alt",              0x00E2, 0x0038),
    AddHidKeyboardInfo("Left Win",              0x00E3, 0xE05B),
    AddHidKeyboardInfo("Right Ctrl",            0x00E4, 0xE01D),
    AddHidKeyboardInfo("Right Shift ",          0x00E5, 0x0036),
    AddHidKeyboardInfo("Right Alt",             0x00E6, 0xE038),
    AddHidKeyboardInfo("Right Win",             0x00E7, 0xE05C),
    
    AddHidKeyboardInfo("LCtrl",                 0x00E0, 0x001D),
    AddHidKeyboardInfo("LShift",                0x00E1, 0x002A),
    AddHidKeyboardInfo("LAlt",                  0x00E2, 0x0038),
    AddHidKeyboardInfo("LWin",                  0x00E3, 0xE05B),
    AddHidKeyboardInfo("RCtrl",                 0x00E4, 0xE01D),
    AddHidKeyboardInfo("RShift ",               0x00E5, 0x0036),
    AddHidKeyboardInfo("RAlt",                  0x00E6, 0xE038),
    AddHidKeyboardInfo("RWin",                  0x00E7, 0xE05C),
    AddHidKeyboardInfo("Left Windows",          0x00E3, 0xE05B),
    AddHidKeyboardInfo("Right Windows",         0x00E7, 0xE05C),
    AddHidKeyboardInfo("L Windows",             0x00E3, 0xE05B),
    AddHidKeyboardInfo("R Windows",             0x00E7, 0xE05C),
    
    AddHidKeyboardInfo("Prnt Scrn",             0x0046, 0xE037),
    AddHidKeyboardInfo("Esc",                   0x0029, 0x0001),
};

std::map<_tstring, HID_SCANCODE_INFO> g_mapHidScanFind;                 // 查找用映射表

// 初始化扫描码映射表
static void InitializeHidScanMap()
{
    if (!g_mapHidScanFind.empty())
    {
        return;
    }

    for (const auto& item : g_mapHidScanCompatible)
    {
        _tstring strName;
        for (const auto& ch : item.first)
        {
            if (_T(' ') != ch)
            {
                strName.push_back((TCHAR)std::tolower((int)ch));
            }
        }

        g_mapHidScanFind.insert(std::make_pair(strName, item.second));
    }
}

std::map<_tstring, HID_SCANCODE_INFO>::const_iterator FindKeyName(const _tstring& strKeyName)
{
    _tstring strTemp;
    for (const auto& ch : strKeyName)
    {
        if (_T(' ') != ch)
        {
            strTemp.push_back((TCHAR)std::tolower((int)ch));
        }
    }

    InitializeHidScanMap();
    return g_mapHidScanFind.find(strTemp);
}

_tstring CHidKeyUtils::GetNameByScanCode(
    uint16_t wScan                  // 按键扫描码
)
{
    InitializeHidScanMap();

    _tstring strKeyName;
    for (const auto& item : g_mapHidScanOrigin)
    {
        if (wScan == item.second.nScanCode)
        {
            strKeyName = item.second.strName;
            break;
        }
    }

    return strKeyName;
}

_tstring CHidKeyUtils::GetNameByUsageID(
    uint8_t nUsageID
)
{
    InitializeHidScanMap();

    _tstring strKeyName;
    for (const auto& item : g_mapHidScanOrigin)
    {
        if (nUsageID == item.second.nUsageID)
        {
            strKeyName = item.second.strName;
            break;
        }
    }

    return strKeyName;
}

uint16_t CHidKeyUtils::GetScanCode(const _tstring& strKeyName)
{
    auto itFind = FindKeyName(strKeyName);

    if (g_mapHidScanFind.end() == itFind)
    {
        return 0;
    }

    return itFind->second.nScanCode;
}

uint8_t CHidKeyUtils::GetUsageID(const _tstring& strKeyName)
{
    auto itFind = FindKeyName(strKeyName);

    if (g_mapHidScanFind.end() == itFind)
    {
        return 0;
    }

    return itFind->second.nUsageID;
}

bool CHidKeyUtils::IsExistsKey(
    const _tstring& strKeyName
)
{
    return g_mapHidScanFind.end() != FindKeyName(strKeyName);
}

bool CHidKeyUtils::IsExtendedKey(
    const _tstring& strKeyName
)
{
    auto itFind = FindKeyName(strKeyName);
    if (g_mapHidScanFind.end() == itFind)
    {
        return false;
    }

    return 0xE000 & itFind->second.nScanCode;
}

bool CHidKeyUtils::SendKeyByName(
    const _tstring& strKeyName,
    bool fDown/* = true*/,
    bool fUp/* = true*/
)
{
    uint16_t nScanCode = GetScanCode(strKeyName);
    if (0 == nScanCode)
    {
        return false;
    }

    return SendKeyByScanCode(nScanCode, fDown, fUp);
}

bool CHidKeyUtils::SendKeyByScanCode(
    uint16_t wScan,
    bool fDown/* = true*/,
    bool fUp/* = true*/
)
{
    INPUT inputs[0x02] = { 0 };
    UINT uSendCount = 0;
    DWORD dwFlags = KEYEVENTF_SCANCODE;

    if (0xE000 & wScan)
    {
        dwFlags |= KEYEVENTF_EXTENDEDKEY;
    }

    if (fDown)
    {
        inputs[uSendCount].type = INPUT_KEYBOARD;
        inputs[uSendCount].ki.wScan = wScan;
        inputs[uSendCount].ki.dwFlags = dwFlags;
        uSendCount++;
    }

    if (fUp)
    {
        inputs[uSendCount].type = INPUT_KEYBOARD;
        inputs[uSendCount].ki.wScan = wScan;
        inputs[uSendCount].ki.dwFlags = dwFlags | KEYEVENTF_KEYUP;
        uSendCount++;
    }

    UINT uCount = ::SendInput(uSendCount, inputs, sizeof(INPUT));

    return uSendCount == uCount;
}
bool CHidKeyUtils::SendKeyByVkCode(
    uint16_t wVk,
    bool fDown/* = true*/,
    bool fUp/* = true*/
)
{
    INPUT inputs[0x02] = { 0 };
    UINT uSendCount = 0;
    DWORD dwFlags = 0;

    if (0 == wVk)
    {
        return false;
    }

    if (fDown)
    {
        inputs[uSendCount].type = INPUT_KEYBOARD;
        inputs[uSendCount].ki.wVk = wVk;
        inputs[uSendCount].ki.dwFlags = dwFlags;
        uSendCount++;
    }

    if (fUp)
    {
        inputs[uSendCount].type = INPUT_KEYBOARD;
        inputs[uSendCount].ki.wVk = wVk;
        inputs[uSendCount].ki.dwFlags = dwFlags | KEYEVENTF_KEYUP;
        uSendCount++;
    }

    UINT uCount = ::SendInput(uSendCount, inputs, sizeof(INPUT));

    return uSendCount == uCount;
}

bool CHidKeyUtils::SendKeyByUsageID(
    uint8_t nUsageID,
    bool fDown/* = true*/,
    bool fUp/* = true*/
)
{
    uint16_t nScanCode = 0;

    for (const auto& item : g_mapHidScanOrigin)
    {
        if (nUsageID == item.second.nUsageID)
        {
            nScanCode = item.second.nScanCode;
            break;
        }
    }

    if (0 == nScanCode)
    {
        return false;
    }

    return SendKeyByScanCode(nScanCode, fDown, fUp);
}