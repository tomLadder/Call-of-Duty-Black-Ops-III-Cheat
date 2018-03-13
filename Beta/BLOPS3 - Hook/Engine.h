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
	char _0x0008[24];
	__int32 iFrameTime; //0x0020 
	char _0x0024[92];
	vec3_t vecOrigin; //0x0080 
	char _0x008C[808];
	__int32 Health; //0x03B4 
	char _0x03B8[4];
	__int32 MaxHealth; //0x03BC 
	char _0x03C0[804];
	__int32 iPrimaryAmmo; //0x06E4 
	__int32 iSecondaryAmmo; //0x06E8 
	__int32 iGrenadeAmmo; //0x06EC 
	__int32 iFlashAmmo; //0x06F0 
	char _0x06F4[332];

};//Size=0x0840

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
	char _0x0000[64];
	vec3_t vecOrigin; //0x0040 
	char _0x004C[4];
	float fYaw; //0x0050 
	char _0x0054[1340];
	__int32 ET_TYPE; //0x0590 
	char _0x0594[824];
	BYTE bAllive; //0x08CC 
	char _0x08CD[11];

	bool isAlive()
	{
		return this->bAllive == 2;
	}
};

class clientinfo_t
{
public:
	__int32 iClientNumber; //0x0000 
	char _0x0004[4];
	__int32 iTeam; //0x0008 
	char _0x000C[32];
	char cName[32]; //0x002C 
	char _0x004C[308];

};//Size=0x0180

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
