#include "CFakerInputHelper.h"

CFakerInputHelper::CFakerInputHelper()
    :
    m_pClient(nullptr),
    m_fConnect(false)
{
    memset(m_Keys, 0, sizeof(m_Keys));
    m_Modifier.Key = 0;
    m_MouseButton.Button = 0;
}

CFakerInputHelper::~CFakerInputHelper()
{
    Uninitialize();
}


bool CFakerInputHelper::Initialize()
{
    bool bResult = false;

    if (m_pClient)
    {
        return true;
    }

    do
    {
        m_pClient = fakerinput_alloc();
        if (!m_pClient)
        {
            break;
        }

        m_fConnect = fakerinput_connect(m_pClient);
        if (!m_fConnect)
        {
            break;
        }

        bResult = true;

    } while (false);

    if (!bResult)
    {
        Uninitialize();
    }

    return bResult;
}

void CFakerInputHelper::Uninitialize()
{
    if (m_pClient)
    {
        ReleaseKeys();
        ReleaseMouseKey();
        if (m_fConnect)
        {
            fakerinput_disconnect(m_pClient);
        }
        fakerinput_free(m_pClient);
        m_pClient = nullptr;
        m_fConnect = false;
    }
}

bool CFakerInputHelper::IsConnected() const
{
    return m_fConnect;
}

void CFakerInputHelper::ReleaseKeys()
{
    if (m_pClient)
    {
        uint8_t codes[6] = { 0 };
        fakerinput_update_keyboard(m_pClient, 0, codes);
    }
}

void CFakerInputHelper::ReleaseMouseKey()
{
    if (m_pClient)
    {
        fakerinput_update_absolute_mouse(m_pClient, 0, 0, 0, 0, 0);
    }
}

bool CFakerInputHelper::MouseMove(
    uint16_t x, 
    uint16_t y
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    fakerinput_update_relative_mouse(m_pClient, m_MouseButton.Button, x, y, 0, 0);

    return true;
}

bool CFakerInputHelper::MouseMoveTo(
    uint16_t x, 
    uint16_t y
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    fakerinput_update_absolute_mouse(m_pClient, m_MouseButton.Button, x, y, 0, 0);

    return true;
}

bool CFakerInputHelper::MouseWheel(
    int8_t v, 
    int8_t h
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    fakerinput_update_relative_mouse(m_pClient, m_MouseButton.Button, 0, 0, v, h);

    return true;
}

bool CFakerInputHelper::MouseClick(
    MOUSE_BUTTON button, 
    uint16_t x, 
    uint16_t y
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    MouseButton(button, true, x, y);
    MouseButton(button, false, x, y);

    return true;
}

bool CFakerInputHelper::Keyboard(
    MODIFIER_KEY modifier,
    uint8_t keyCode, 
    bool fDown/* = true*/
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    return _Keyboard(modifier, &keyCode, 1, fDown);
}

bool CFakerInputHelper::KeyboardDown(
    uint8_t key1,
    uint8_t key2,
    uint8_t key3,
    uint8_t key4,
    uint8_t key5,
    uint8_t key6 
)
{
    uint8_t keys[6] = { key1,key2,key3,key4,key5,key6 };
    return _Keyboard(MODIFIER_KEY(), keys, 6, true);
}

bool CFakerInputHelper::KeyboardUp(
    uint8_t key1,
    uint8_t key2,
    uint8_t key3,
    uint8_t key4,
    uint8_t key5,
    uint8_t key6 
)
{
    uint8_t keys[6] = { key1,key2,key3,key4,key5,key6 };
    return _Keyboard(MODIFIER_KEY(), keys, 6, false);
}

bool CFakerInputHelper::KeyboardDown(
    MODIFIER_KEY modifier,
    uint8_t key1,
    uint8_t key2,
    uint8_t key3,
    uint8_t key4,
    uint8_t key5,
    uint8_t key6
)
{
    uint8_t keys[6] = { key1,key2,key3,key4,key5,key6 };
    return _Keyboard(modifier, keys, 6, true);
}

bool CFakerInputHelper::KeyboardUp(
    MODIFIER_KEY modifier,
    uint8_t key1,
    uint8_t key2,
    uint8_t key3,
    uint8_t key4,
    uint8_t key5,
    uint8_t key6
)
{
    uint8_t keys[6] = { key1,key2,key3,key4,key5,key6 };
    return _Keyboard(modifier, keys, 6, false);
}

bool CFakerInputHelper::Keyboard(
    MODIFIER_KEY modifier,
    std::vector<uint8_t> vkeys,
    bool fDown/* = true*/
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    return _Keyboard(modifier, vkeys.data(), vkeys.size(), fDown);
}

bool CFakerInputHelper::MouseButton(
    MOUSE_BUTTON button,
    bool fDown,
    uint16_t x, 
    uint16_t y
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    if (fDown)
    {
        m_MouseButton.Button |= button.Button;
        fakerinput_update_absolute_mouse(m_pClient, m_MouseButton.Button, x, y, 0, 0);
    }
    else
    {
        m_MouseButton.Button &= ~button.Button;
        fakerinput_update_absolute_mouse(m_pClient, m_MouseButton.Button, x, y, 0, 0);
    }

    return true;
}

bool CFakerInputHelper::_Keyboard(
    MODIFIER_KEY modifier,      // 修饰键
    const uint8_t* keys,        // 普通键
    size_t        count,        // 按键数量(0 - 6)
    bool fDown = true           // 是否按下
)
{
    if (!(m_pClient && m_fConnect))
    {
        return false;
    }

    if (count > 6)
    {
        count = 6;
    }

    if (fDown)
    {
        m_Modifier.Key |= modifier.Key;

        for (int i = 0; i < count; i++)
        {
            if (0 == keys[i])
            {
                continue;
            }

            // 查找是否已存在
            bool fExist = false;
            for (int j = 0; j < sizeof(m_Keys); j++)
            {
                if (keys[i] == m_Keys[j])
                {
                    fExist = true;
                    break;
                }
            }

            // 按键已经按下过了, 不处理
            if (fExist)
            {
                continue;
            }

            // 查找按键空位
            int nKeyIndex = 0;
            for (int j = 0; j < sizeof(m_Keys); j++)
            {
                if (0 == m_Keys[j])
                {
                    break;
                }
                nKeyIndex++;
            }

            // 插入新的按键
            if (nKeyIndex < sizeof(m_Keys))
            {
                m_Keys[nKeyIndex] = keys[i];
            }
        }
    }
    else
    {
        m_Modifier.Key &= ~modifier.Key;

        // 释放指定按键
        for (int i = 0; i < sizeof(m_Keys); i++)
        {
            // 查找未释放的按键
            if (0 == m_Keys[i])
            {
                continue;
            }

            //若未释放的按键与指定按键相同, 则释放掉
            for (int j = 0; j < count; j++)
            {
                if (keys[j] == m_Keys[i])
                {
                    m_Keys[i] = 0;       //清除按键状态
                }
            }
        }
    }

    return fakerinput_update_keyboard(m_pClient, m_Modifier.Key, m_Keys);
}
