#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Console.h"

bool currentShift = false;
HHOOK hkb;
HHOOK mkb;
bool end;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam,
	LPARAM lParam)
{

	if (nCode == HC_ACTION && (wParam == WM_SYSKEYDOWN || wParam == WM_KEYDOWN)) {
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
		std::cout << p->vkCode << std::endl;
		if (p->vkCode == VK_LSHIFT || p->vkCode == VK_RSHIFT)
		{
			currentShift = true;
		}

		if (p->vkCode == 48) // =
		{
			if (currentShift)
				Console::Instance()->addKey('=');
			else
				Console::Instance()->addKey('0');
		}
		else if (currentShift && (isalnum(p->vkCode) || isblank(p->vkCode)))
		{
			Console::Instance()->addKey((char)toupper((char)p->vkCode));
		}
		else if (isalnum(p->vkCode) || isblank(p->vkCode))
		{
			Console::Instance()->addKey((char)tolower((char)p->vkCode));
		}
		else if (p->vkCode == VK_RETURN || p->vkCode == VK_BACK || p->vkCode == VK_INSERT)
		{
			Console::Instance()->addKey((char)p->vkCode);
		}
		else if (p->vkCode == 189) // -
		{
			if (currentShift)
				Console::Instance()->addKey('_');
			else
				Console::Instance()->addKey('-');
		}
		else if (p->vkCode == 187) // +
		{
			if (currentShift)
				Console::Instance()->addKey('*');
			else
				Console::Instance()->addKey('+');
		}
		else if (p->vkCode == 190) // .
		{
			if (currentShift)
				Console::Instance()->addKey(':');
			else
				Console::Instance()->addKey('.');
		}
	}
	else if (nCode == HC_ACTION && (wParam == WM_SYSKEYUP || wParam == WM_KEYUP))
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
		if (p->vkCode == VK_LSHIFT || p->vkCode == VK_RSHIFT)
		{
			currentShift = false;
		}
	}
	LRESULT RetVal = CallNextHookEx(hkb, nCode, wParam, lParam);
	return  RetVal;
}

LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (wParam == WM_MOUSEWHEEL)
	{
		PMSLLHOOKSTRUCT p = (PMSLLHOOKSTRUCT)lParam;
		if (p->mouseData == 4287102976)
		{
			Console::Instance()->eventScrollDown();
		}
		else if (p->mouseData == 7864320)
		{
			Console::Instance()->eventScrollUp();
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

BOOL __stdcall installhook(HMODULE module)
{
	MSG msg;
	hkb = SetWindowsHookEx(WH_KEYBOARD_LL, &LowLevelKeyboardProc, module, NULL);
	mkb = SetWindowsHookEx(WH_MOUSE_LL, &mouseHookProc, module, NULL);

	while (!end && !GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return TRUE;
}