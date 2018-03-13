#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <Tools.h>
#include "Console.h"
#include <MinHook.h>
#include "GlobalVars.h"
#include "BO3Render.h"
#include "BO3Engine.h"
#include "ColorManager.h"
#include "WindowsHooks.h"
#include "EspManager.h"

#if defined _M_X64
#pragma comment(lib, "libMinHook-x64-v140-md.lib")
#endif

bool first = true;
bool first2 = true;
__int64 font = 0;
__int64 materialWhite = 0;

int __fastcall hCG_Draw2D(int localClientNum)
{
	if(first)
	{
		first = false;
	}
	int val = pCG_Draw2D(localClientNum);
	//Console::Instance()->draw();
	EspManager::Instance()->draw();
	return val;
}

BOOL Init()
{
	Tools::Console::open();
	Tools::Console::printLine("* Call of Duty - Black Ops 3 Framework by teohasele/tomladder *");
	Tools::Console::setTitle("Call of Duty - Black Ops 3 Framework");
	std::cout << std::hex << Tools::Memory::FindProxy() << std::endl;

	if (MH_Initialize() != MH_OK) {
		Tools::Console::printLog("MinHook Init failed!\n");
		return 1;
	}

	//CG_Draw2D
	if (MH_CreateHook((LPVOID)(OFFCG_Draw2D), &hCG_Draw2D, reinterpret_cast<LPVOID*>(&pCG_Draw2D)) != MH_OK) {
		Tools::Console::printLog("MinHook creation failed!");
		return 1;
	}

	if (MH_EnableHook((LPVOID)(OFFCG_Draw2D)) != MH_OK) {
		Tools::Console::printLog("MinHook enable failed!");
		return 1;
	}

	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&installhook, NULL, NULL, NULL);
		CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(&Init), 0, NULL, nullptr);
		break;
	}

	return TRUE;
}