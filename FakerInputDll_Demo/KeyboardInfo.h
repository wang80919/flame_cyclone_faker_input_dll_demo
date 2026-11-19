#pragma once
#include <windows.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdint.h>
#include <tchar.h>

#ifdef _UNICODE
using _tstring = std::wstring;
#else
using _tstring = std::string;
#endif

typedef struct _KBDATA_INFO {
    WORD vkCode;
    WORD scanCode;
    DWORD flags;
    uint8_t nUsageID;

    _KBDATA_INFO() :vkCode(0), scanCode(0), flags(0), nUsageID(0) {};

    _KBDATA_INFO(WORD vk, WORD sc, DWORD f, uint8_t usage = 0) : vkCode(vk), scanCode(sc), flags(f), nUsageID(usage) {};

    _KBDATA_INFO(const _KBDATA_INFO& r) :vkCode(r.vkCode), scanCode(r.scanCode), flags(r.flags), nUsageID(r.nUsageID) {}

    bool operator == (const _KBDATA_INFO& r) const
    {
        return (this->scanCode == r.scanCode) && (this->flags & 0x01) == (r.flags & 0x01);
    }

    bool operator != (const _KBDATA_INFO& r) const
    {
        return !(*this == r);
    }

    bool operator < (const _KBDATA_INFO& r) const
    {
        if (this->scanCode != r.scanCode) return this->scanCode < r.scanCode;
        return (this->flags & 0x01) < (r.flags & 0x01);
    }

    void operator=(const _KBDATA_INFO& r)
    {
        this->vkCode = r.vkCode;
        this->scanCode = r.scanCode;
        this->flags = r.flags;
    }

} KBDATA_INFO, FAR* LPKBDATA_INFO, * PKBDATA_INFO;

extern std::map<_tstring, KBDATA_INFO> g_KeyMap;

LPCTSTR GetHidKeyboardName(uint8_t usage_id);
