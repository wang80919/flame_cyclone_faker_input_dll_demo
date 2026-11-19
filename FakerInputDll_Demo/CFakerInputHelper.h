#pragma once

#include <windows.h>
#include <vector>
#include "FakerInputDll/include/fakerinputclient.h"
#include <stdint.h>
#include <string>
#include <tchar.h>

#ifdef _UNICODE
using _tstring = std::wstring;
#else
using _tstring = std::string;
#endif

#ifdef _WIN64
#pragma comment(lib,"FakerInputDll/lib/x64/FakerInputDll.lib")
#else
#pragma comment(lib,"FakerInputDll/lib/x86/FakerInputDll.lib")
#endif

// 禁用无名结构体/联合体警告 Disable warning C4201:nameless struct/union
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable : 4201)

// 鼠标按键按下标志
enum eFakerInputMouseKey
{
    eMouseKey_Left        = 0x01 << 0,
    eMouseKey_Right       = 0x01 << 1,
    eMouseKey_Middle      = 0x01 << 2,
    eMouseKey_XButton1    = 0x01 << 3,
    eMouseKey_XButton2    = 0x01 << 4,
};

// 修饰键
enum eFakerInputShiftFlag
{
    eShiftFlag_LControl   = 0x01 << 0,
    eShiftFlag_LShift     = 0x01 << 1,
    eShiftFlag_LAlt       = 0x01 << 2,
    eShiftFlag_LWin       = 0x01 << 3,
    eShiftFlag_RControl   = 0x01 << 4,
    eShiftFlag_RShift     = 0x01 << 5,
    eShiftFlag_RAlt       = 0x01 << 6,
    eShiftFlag_RWin       = 0x01 << 7,
};

typedef union _MOUSE_BUTTON
{
    uint8_t Button;
    struct
    {
        uint8_t Left : 1;           // 鼠标左键
        uint8_t Right : 1;          // 鼠标右键
        uint8_t Middle : 1;         // 鼠标中键
        uint8_t X1 : 1;             // 附加按钮1
        uint8_t X2 : 1;             // 附加按钮2
    };

    _MOUSE_BUTTON(bool fL = 0, bool fR = 0, bool fM = 0, bool fX1 = 0, bool fX2 = 0)
    {
        Button = 0;
        Left = fL;
        Right = fR;
        Middle = fM;
        X1 = fX1;
        X2 = fX2;
    }

}MOUSE_BUTTON;

typedef union _MODIFIER_KEY
{
    uint8_t Key;
    struct
    {
        uint8_t LCtrl : 1;          // 左Ctrl
        uint8_t LShift : 1;         // 左Shift
        uint8_t LAlt : 1;           // 左Alt
        uint8_t LWin : 1;           // 左Win
        uint8_t RCtrl : 1;          // 右Ctrl
        uint8_t RShift : 1;         // 右Shift
        uint8_t RAlt : 1;           // 右Alt
        uint8_t RWin : 1;           // 右Win
    };

    _MODIFIER_KEY(
        bool lc = 0, bool ls = 0, bool la = 0, bool lw = 0, 
        bool rc = 0, bool rs = 0, bool ra = 0, bool rw = 0
    )
    {
        Key = 0;
        LCtrl   = lc;
        LShift  = ls;
        LAlt    = la;
        LWin    = lw;
        RCtrl   = rc;
        RShift  = rs;
        RAlt    = ra;
        RWin    = rw;
    }

}MODIFIER_KEY;

// 普通按键
enum eFakerInputKey
{
    eKey_A                  = 0x04,
    eKey_B                  = 0x05,
    eKey_C                  = 0x06,
    eKey_D                  = 0x07,
    eKey_E                  = 0x08,
    eKey_F                  = 0x09,
    eKey_G                  = 0x0A,
    eKey_H                  = 0x0B,
    eKey_I                  = 0x0C,
    eKey_J                  = 0x0D,
    eKey_K                  = 0x0E,
    eKey_L                  = 0x0F,
    eKey_M                  = 0x10,
    eKey_N                  = 0x11,
    eKey_O                  = 0x12,
    eKey_P                  = 0x13,
    eKey_Q                  = 0x14,
    eKey_R                  = 0x15,
    eKey_S                  = 0x16,
    eKey_T                  = 0x17,
    eKey_U                  = 0x18,
    eKey_V                  = 0x19,
    eKey_W                  = 0x1A,
    eKey_X                  = 0x1B,
    eKey_Y                  = 0x1C,
    eKey_Z                  = 0x1D,

    eKey_Number_1           = 0x1E,
    eKey_Number_2           = 0x1F,
    eKey_Number_3           = 0x20,
    eKey_Number_4           = 0x21,
    eKey_Number_5           = 0x22,
    eKey_Number_6           = 0x23,
    eKey_Number_7           = 0x24,
    eKey_Number_8           = 0x25,
    eKey_Number_9           = 0x26,
    eKey_Number_0           = 0x27,

    eKey_Enter              = 0x28,
    eKey_Escape             = 0x29,
    eKey_Backspace          = 0x2A,
    eKey_Tab                = 0x2B,
    eKey_Spacebar           = 0x2C,
    eKey_Minus              = 0x2D,
    eKey_Equals             = 0x2E,
    eKey_OpenBrace          = 0x2F,
    eKey_CloseBrace         = 0x30,
    eKey_Backslash          = 0x31,
    eKey_Hash               = 0x32,
    eKey_Semicolon          = 0x33,
    eKey_Quote              = 0x34,
    eKey_Tilde              = 0x35,
    eKey_Comma              = 0x36,
    eKey_Dot                = 0x37,
    eKey_ForwardSlash       = 0x38,
    eKey_CapsLock           = 0x39,

    eKey_F1                 = 0x3A,
    eKey_F2                 = 0x3B,
    eKey_F3                 = 0x3C,
    eKey_F4                 = 0x3D,
    eKey_F5                 = 0x3E,
    eKey_F6                 = 0x3F,
    eKey_F7                 = 0x40,
    eKey_F8                 = 0x41,
    eKey_F9                 = 0x42,
    eKey_F10                = 0x43,
    eKey_F11                = 0x44,
    eKey_F12                = 0x45,
    eKey_F13                = 0x68, //不支持
    eKey_F14                = 0x69, //不支持
    eKey_F15                = 0x6A, //不支持
    eKey_F16                = 0x6B, //不支持
    eKey_F17                = 0x6C, //不支持
    eKey_F18                = 0x6D, //不支持
    eKey_F19                = 0x6E, //不支持
    eKey_F20                = 0x6F, //不支持
    eKey_F21                = 0x70, //不支持
    eKey_F22                = 0x71, //不支持
    eKey_F23                = 0x72, //不支持
    eKey_F24                = 0x73, //不支持

    eKey_PrintScreen        = 0x46,
    eKey_ScrollLock         = 0x47,
    eKey_Pause              = 0x48,
    eKey_Insert             = 0x49,
    eKey_Home               = 0x4A,
    eKey_PageUp             = 0x4B,
    eKey_Delete             = 0x4C,
    eKey_End                = 0x4D,
    eKey_PageDown           = 0x4E,
    eKey_RightArrow         = 0x4F,
    eKey_LeftArrow          = 0x50,
    eKey_DownArrow          = 0x51,
    eKey_UpArrow            = 0x52,
    eKey_NumLock            = 0x53,
    eKey_Keypad_Divide      = 0x54,
    eKey_Keypad_Multiply    = 0x55,
    eKey_Keypad_Subtract    = 0x56,
    eKey_Keypad_Add         = 0x57,
    eKey_Keypad_Enter       = 0x58,
    eKey_Keypad_1           = 0x59,
    eKey_Keypad_2           = 0x5A,
    eKey_Keypad_3           = 0x5B,
    eKey_Keypad_4           = 0x5C,
    eKey_Keypad_5           = 0x5D,
    eKey_Keypad_6           = 0x5E,
    eKey_Keypad_7           = 0x5F,
    eKey_Keypad_8           = 0x60,
    eKey_Keypad_9           = 0x61,
    eKey_Keypad_0           = 0x62,
    eKey_Keypad_Decimal     = 0x63,
    eKey_Keypad_Separator   = 0x64,
    eKey_Keypad_Application = 0x65
};

class CFakerInputHelper
{
public:

    CFakerInputHelper();
    ~CFakerInputHelper();

    bool Initialize();
    void Uninitialize();
    bool IsConnected() const;
    void ReleaseKeys();
    void ReleaseMouseKey();

    // 相对移动
    bool MouseMove(
        uint16_t x,                 // 横向移动像素值
        uint16_t y                  // 纵向移动像素值
    );

    // 绝对移动
    bool MouseMoveTo(
        uint16_t x,                 // 归一化绝对横坐标 0 - 32767
        uint16_t y                  // 归一化绝对纵坐标 0 - 32767
    );

    // 滚轮
    bool MouseWheel(
        int8_t v,                   //  垂直滚动值
        int8_t h = 0                //  水平滚动值
    );

    // 单击
    bool MouseClick(
        MOUSE_BUTTON button,        // 鼠标按键
        uint16_t x = 0,             // 归一化绝对横坐标 0 - 32767
        uint16_t y = 0              // 归一化绝对纵坐标 0 - 32767
    );

    // 键盘
    bool Keyboard(
        MODIFIER_KEY modifier,      // 修饰键
        uint8_t keyCode,            // 普通键
        bool fDown = true           // 是否按下
    );

    // 普通键按下
    bool KeyboardDown(
        uint8_t key1 = 0,           // 普通键1
        uint8_t key2 = 0,           // 普通键2
        uint8_t key3 = 0,           // 普通键3
        uint8_t key4 = 0,           // 普通键4
        uint8_t key5 = 0,           // 普通键5
        uint8_t key6 = 0            // 普通键6
    );

    // 普通键弹起
    bool KeyboardUp(
        uint8_t key1 = 0,           // 普通键1
        uint8_t key2 = 0,           // 普通键2
        uint8_t key3 = 0,           // 普通键3
        uint8_t key4 = 0,           // 普通键4
        uint8_t key5 = 0,           // 普通键5
        uint8_t key6 = 0            // 普通键6
    );

    // 修饰键 + 普通键按下
    bool KeyboardDown(
        MODIFIER_KEY modifier,      // 修饰键
        uint8_t key1 = 0,           // 普通键1
        uint8_t key2 = 0,           // 普通键2
        uint8_t key3 = 0,           // 普通键3
        uint8_t key4 = 0,           // 普通键4
        uint8_t key5 = 0,           // 普通键5
        uint8_t key6 = 0            // 普通键6
    );

    // 修饰键 + 普通键弹起
    bool KeyboardUp(
        MODIFIER_KEY modifier,      // 修饰键
        uint8_t key1 = 0,           // 普通键1
        uint8_t key2 = 0,           // 普通键2
        uint8_t key3 = 0,           // 普通键3
        uint8_t key4 = 0,           // 普通键4
        uint8_t key5 = 0,           // 普通键5
        uint8_t key6 = 0            // 普通键6
    );

    // 键盘
    bool Keyboard(
        MODIFIER_KEY modifier,      // 修饰键
        std::vector<uint8_t> vkeys, // 普通键列表
        bool fDown = true           // 是否按下
    );

    // 按钮
    bool MouseButton(
        MOUSE_BUTTON button,        // 鼠标按钮
        bool fDown = true,          // 是否按下按钮
        uint16_t x = 0,             // 归一化绝对横坐标 0 - 32767
        uint16_t y = 0              // 归一化绝对纵坐标 0 - 32767
    );

private:

    // 键盘
    bool _Keyboard(
        MODIFIER_KEY modifier,      // 修饰键
        const uint8_t* keys,        // 普通键
        size_t count,               // 按键数量(0 - 6)
        bool fDown                  // 是否按下
    );

private:

    uint8_t                 m_Keys[6] = { 0 };          // 当前普通键
    MODIFIER_KEY            m_Modifier;                 // 当前修饰键
    MOUSE_BUTTON            m_MouseButton;              // 当前鼠标键
    pfakerinput_client      m_pClient;                  // 客户端
    bool                    m_fConnect;                 // 连接状态
};
