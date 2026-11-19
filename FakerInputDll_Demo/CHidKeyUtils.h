#pragma once

#include <string>
#include <stdint.h>
#include <map>
#include <tchar.h>

#ifdef _UNICODE
using _tstring = std::wstring;
#else
using _tstring = std::string;
#endif

class CHidKeyUtils
{
public:

    // 获取按键 扫描码
    static uint16_t GetScanCode(
        const _tstring& strKeyName      // 按键名
    );

    // 获取按键 HID 用法 ID
    static uint8_t GetUsageID(
        const _tstring& strKeyName      // 按键名
    );

    // 获取按键名
    static _tstring GetNameByScanCode(
        uint16_t wScan                  // 按键扫描码
    );

    // 获取按键名
    static _tstring GetNameByUsageID(
        uint8_t nUsageID                // 按键扫描码
    );

    // 是否存在按键
    static bool IsExistsKey(
        const _tstring& strKeyName      // 按键名
    );

    // 是否为扩展键
    static bool IsExtendedKey(
        const _tstring& strKeyName      // 按键名
    );

    // 发送按键(按键名方式)
    static bool SendKeyByName(
        const _tstring& strKeyName,     // 按键名
        bool fDown = true,              // 按下
        bool fUp = true                 // 弹起
    );

    // 发送按键(扫描码方式)
    static bool SendKeyByScanCode(
        uint16_t wScan,                 // 按键扫描码
        bool fDown = true,              // 按下
        bool fUp = true                 // 弹起
    );

    // 发送按键(虚键码方式)
    static bool SendKeyByVkCode(
        uint16_t wVk,                 // 按键扫描码
        bool fDown = true,              // 按下
        bool fUp = true                 // 弹起
    );

    // 发送按键(HID 用法 ID 方式)
    static bool SendKeyByUsageID(
        uint8_t nUsageID,               // 按键扫描码
        bool fDown = true,              // 按下
        bool fUp = true                 // 弹起
    );
};
