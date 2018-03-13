#pragma once

#pragma once

#include <Windows.h>
#include "vec3.h"
#include "vec2.h"

class cg_t;
class cgs_t;
class entity_t;
class clientinfo_t;
class input_t;
class usercmd_t;
class refdef_t;

class cg_t
{
public:
	__int64 iClientNum; //0x0000 
	char pad_0x0008[0x18]; //0x0008
	__int64 iFrameTime; //0x0020 
	char pad_0x0028[0x58]; //0x0028
	vec3_t vecOrigin; //0x0080 
	char pad_0x008C[0x32C]; //0x008C
	__int32 iHealth; //0x03B8 
	char pad_0x03BC[0x4]; //0x03BC
	__int32 iMaxHealth; //0x03C0 
	char pad_0x03C4[0x31C]; //0x03C4
	__int32 iPrimaryAmmo; //0x06E0 
	__int32 iSecondaryAmmo; //0x06E4 
	__int32 iGrenadeAmmo; //0x06E8 
	__int32 iFlashAmmo; //0x06EC 
	char pad_0x06F0[0x19D0]; //0x06F0

};//Size=0x20C0

class cgs_t
{
public:
	char _0x0000[8];
	__int32 iWidth; //0x0008 
	__int32 iHeight; //0x000C 
	char _0x0010[320];
	__int32 iMaxPlayer; //0x0150 
	char _0x0154[13164];

};//Size=0x34C0

class entity_t
{
public:
	char pad_0x0000[0x40]; //0x0000
	vec3_t vOrigin; //0x0040 
	char pad_0x004C[0x4]; //0x004C
	float Yaw; //0x0050 
	char pad_0x0054[0x544]; //0x0054
	unsigned char ET_TYPE; //0x0598 
	char pad_0x0599[0x35B]; //0x0599
	unsigned char allive; //0x08F4  & 2
	char pad_0x08F5[0x13]; //0x08F5

	bool isAlive()
	{
		return (this->allive & 0x2) != 0;
	}
};//Size=0x0908

class clientinfo_t
{
public:
	char pad_0x0000[0x8]; //0x0000
	__int32 iClientNum; //0x0008 
	char cName[32]; //0x000C 
	char pad_0x002C[0x4]; //0x002C
	__int32 iTeam; //0x0030 
	char pad_0x0034[0xE7C]; //0x0034

};//Size=0x0EB0

class input_t
{
public:
	usercmd_t* GetCmd(int localClientNum, int num)
	{
		DWORD64 input = localClientNum * 0x1981a0 + *(DWORD64*)(0x1434400e8);
		return (usercmd_t*)(input + 80 * (num & 0x7F) + 0x10c068);
	}

};//Size=0x2440

class usercmd_t
{
public:
	__int32 iServerTime; //0x0000 
	__int32 iButtons; //0x0004 
	char _0x0008[8];
	__int32 iViewAngleX; //0x0010 
	__int32 iViewAngleY; //0x0014 
	__int32 iViewAngleZ; //0x0018 
	__int32 iWeaponIndex; //0x001C 

};//Size=0x0020

class refdef_t
{
public:
	char _0x0000[8];
	__int32 iWidth; //0x0008 
	__int32 iHeight; //0x000C 
	char _0x0010[96];
	float fFovX; //0x0070 
	float fFovY; //0x0074 
	float N1B5B9CB5; //0x0078 
	char _0x007C[4];
	vec3_t vecOrigin; //0x0080 
	char _0x008C[16];
	vec3_t vecAxisX; //0x009C 
	vec3_t vecAxisY; //0x00A8 
	vec3_t vecAxisZ; //0x00B4 

};//Size=0x00C0
