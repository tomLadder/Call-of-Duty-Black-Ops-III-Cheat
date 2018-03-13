#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <MinHook.h>
#include <stdio.h>
#include <math.h>
#include "GlobalVars.h"
#include "Rendering.h"
#include "Esp.h"
#include "Aimbot.h"
#include "Radar.h"
#include "HealthBar.h"
#include "Menu.h"

#include <iostream>

#if defined _M_X64
#pragma comment(lib, "libMinHook-x64-v120-mdd.lib")
#endif
HealthBar healthBar;
bool firstRun = true;

void InitVars()
{
	//Radar::Instance()->Init(refdef->iWidth - 250.f, 50.f, 200.f, 200.f);
	Radar::Instance()->Init(10.f, 10.f, 200.f, 200.f);
	CODEngine::RegisterTags();
}

int __fastcall hCG_Draw2D(int localClientNum)
{
	int val = pCG_Draw2D(localClientNum);
	if (firstRun)
	{
		//InitVars();
		firstRun = false;
	}
	//Menu::Instance()->Update();
	

	std::cout << "Clientinfo: " << CODEngine::GetClientInfo(0) << std::endl;
	std::cout << "CGT" << CODEngine::GetCGT() << std::endl;
	std::cout << "" << CODEngine::GetEntity(0) << std::endl;
	float color[4] = { 1.f, 0.64f, 0.f, 1.f };
	float color2[4] = { 0.f, 0.f, 1.f, 1.f };
	float color3[4] = { 1.f, 0.f, 0.f, 1.f };
	float color4[4] = { 0.f, 1.f, 0.f, 1.f }; 
	//Esp::Instance()->DrawBoxEsp(color, color2, false);
	//esp.DrawBoneEspLine(color, color2, false, rendering);
	//esp.DrawLineEsp(color3, color4, Bottom, false, rendering);
	//Radar::Instance()->Draw(color, color2, false);
	//healthBar.Draw(rendering);
	//rendering.DrawShader(10, 10, 50, 50, 0, color5, rendering.materialCompassping_enemy);
	//rendering.DrawShader(100, 100, 50, 50, 0, color5, rendering.materialCompassping_friendly_mp);

	//float angel = entities[cg->iClientNum].fYaw;
	//if (angel < 0)
	//	angel = 360 - angel;

	//printf("Angel: %f\n", angel);
	////printf("Called!!!!");
	////pR_AddCmdDrawText(0x7FFFFFFF, "Hallo\0", pR_RegisterFont("fonts/smalldevfont"), 100, 100, 1.5f, 2.0f, 0, color, 0);
	
	return val;
}

void __fastcall hCL_WritePacket(int localClientNum)
{
	int num = pCL_GetCurrentCmdNumber(localClientNum);
	//Aimbot::doSilentAim(input.GetCmd(localClientNum, num), input.GetCmd(localClientNum, num-1), input.GetCmd(localClientNum, num + 1));
	return pCL_WritePacket(localClientNum);
}

__int64 hBG_WeaponFireRecoil(double val, void* ps, float* recoilSpeed, float* kickaVel)
{
	return 0;
}

void startConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
}

BOOL Init()
{
	startConsole();

	if (MH_Initialize() != MH_OK) {
		printf("Init failed!\n");
		return 1;
	}

	//CG_Draw2D
	if (MH_CreateHook((LPVOID)(OFFCG_Draw2D), &hCG_Draw2D, reinterpret_cast<LPVOID*>(&pCG_Draw2D)) != MH_OK) {
		printf("Hook creation failed! %d\n", MH_CreateHook((LPVOID)(OFFCG_Draw2D), &hCG_Draw2D, reinterpret_cast<LPVOID*>(&pCG_Draw2D)));
		return 1;
	}

	if (MH_EnableHook((LPVOID)(OFFCG_Draw2D)) != MH_OK) {
		printf("Hook enable failed %d!\n", MH_EnableHook((LPVOID)(OFFCG_Draw2D)));
		return 1;
	}

	////CL_WritePacket
	//if (MH_CreateHook((LPVOID)(OFFCL_WritePacket), &hCL_WritePacket, reinterpret_cast<LPVOID*>(&pCL_WritePacket)) != MH_OK) {
	//	printf("Hook creation failed! %d\n", MH_CreateHook((LPVOID)(OFFCL_WritePacket), &hCL_WritePacket, reinterpret_cast<LPVOID*>(&pCL_WritePacket)));
	//	return 1;
	//}

	//if (MH_EnableHook((LPVOID)(OFFCL_WritePacket)) != MH_OK) {
	//	printf("Hook enable failed %d!\n", MH_EnableHook((LPVOID)(OFFCL_WritePacket)));
	//	return 1;
	//}

	////Recoil
	//if (MH_CreateHook((LPVOID)(OFFBG_WeaponFireRecoil), &hBG_WeaponFireRecoil, reinterpret_cast<LPVOID*>(&pBG_WeaponFireRecoil)) != MH_OK) {
	//	printf("Hook creation failed! %d\n", MH_CreateHook((LPVOID)(OFFBG_WeaponFireRecoil), &hBG_WeaponFireRecoil, reinterpret_cast<LPVOID*>(&pBG_WeaponFireRecoil)));
	//	return 1;
	//}

	//if (MH_EnableHook((LPVOID)(OFFBG_WeaponFireRecoil)) != MH_OK) {
	//	printf("Hook enable failed %d!\n", MH_EnableHook((LPVOID)(OFFBG_WeaponFireRecoil)));
	//	return 1;
	//}

	return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&Init, NULL, NULL, NULL);
		break;
	default:
		break;
	}

	return TRUE;
}