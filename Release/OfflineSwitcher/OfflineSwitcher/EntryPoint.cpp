#include <Windows.h>
#include <iostream>

#define SWITCH_ADDR 0xE9CE90B8C

void init()
{
	SetConsoleTitle("Call of Duty Black Ops 3 - OfflineSwitcher");
	std::cout << "****************************************************" << std::endl;
	std::cout << "* -> Call of Duty Black Ops 3 - OfflineSwitcher    *" << std::endl;
	std::cout << "* -> Version      65.0.0.0.0                       *" << std::endl;
	std::cout << "* -> Compiled     07.05.2016                       *" << std::endl;
	std::cout << "* -> by teohasele                                  *" << std::endl;
	std::cout << "****************************************************" << std::endl << std::endl;
}

void patch()
{
	std::cout << "Waiting for BlackOps3.exe" << std::endl;
	HWND hwndBlops3 = nullptr;
	DWORD dwProcId;
	while(!hwndBlops3)
	{
		hwndBlops3 = FindWindowA("CoDBlackOps", nullptr);
		Sleep(100);
	}
	std::cout << "Found BlackOps3.exe" << std::endl;
	GetWindowThreadProcessId(hwndBlops3, &dwProcId);
	HANDLE hBlops3 = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcId);
	if(hBlops3)
	{
		char* cbuff = "MPLobbyLANGame";
		WriteProcessMemory(hBlops3, (LPVOID)SWITCH_ADDR, (LPVOID)cbuff, sizeof(cbuff), NULL);
		std::cout << "Successfully switched mode!" << std::endl;
	}
	else
	{
		std::cout << "Error - could not open process!" << std::endl;
	}
	CloseHandle(hBlops3);
}

int main()
{
	init();
	patch();

	getchar();
	return 0;
}