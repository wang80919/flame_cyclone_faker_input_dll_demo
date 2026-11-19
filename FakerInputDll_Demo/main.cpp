#include <windows.h>
#include <locale.h>
#include "CFakerInputHelper.h"
#include "CInputUtils.h"
#include "CHidKeyUtils.h"

int main()
{
	setlocale(LC_ALL, "");

	/*{
		CFakerInputHelper CKeyHelper;
		CKeyHelper.Initialize();
		CKeyHelper.KeyboardDown(MODIFIER_KEY(1, 0, 1, 0), eFakerInputKey::eKey_Delete);
		CKeyHelper.Uninitialize();
	}*/
	CHidKeyUtils::SendKeyByName(_T("LCtrl"), true, false);
	CHidKeyUtils::SendKeyByName(_T("LAlt"), true, false);
	//CHidKeyUtils::SendKeyByVkCode(VK_LCONTROL, 1, 0);
	//CHidKeyUtils::SendKeyByVkCode(VK_LMENU, 1, 0);
	CHidKeyUtils::SendKeyByVkCode(VK_DELETE, 1, 0);

	/*CHidKeyUtils::SendKeyByName(_T("LWin"), true, false);
	CHidKeyUtils::SendKeyByName(_T("R"), true, false);
	CHidKeyUtils::SendKeyByName(_T("R"), false, true);
	CHidKeyUtils::SendKeyByName(_T("LWin"), false, true);*/
	
    return 0;
}

		