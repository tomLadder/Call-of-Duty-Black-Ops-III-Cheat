#pragma once

#pragma once

#include <Windows.h>
#include "vec3.h"
#include "vec2.h"

class cg_t;
class entity_t;
class clientinfo_t;
class refdef_t;

class cg_t
{
public:
	__int32 iClientNum; //0x0000 
	char pad_0x0004[0x1C]; //0x0004
	__int32 iFrameTime; //0x0020 
	char pad_0x0024[0x5C]; //0x0024
	vec3 vecOrigin; //0x0080 
	char pad_0x008C[0x32C]; //0x008C
	__int32 iHealth; //0x03B8 
	char pad_0x03BC[0x4]; //0x03BC
	__int32 iMaxHealth; //0x03C0 
	char pad_0x03C4[0x310]; //0x03C4
	__int32 iPrimaryAmmo; //0x06D4 
	__int32 iSecondaryAmmo; //0x06D8 
	__int32 iGrenadeAmmo; //0x06DC 
	__int32 iFlashAmmo; //0x06E0 
	char pad_0x06E4[0x15C]; //0x06E4

};//Size=0x0840

class entity_t
{
public:
	char pad_0x0000[0x40]; //0x0000
	vec3 vecOrigin; //0x0040 
	char pad_0x004C[0x4]; //0x004C
	float fYaw; //0x0050 
	char pad_0x0054[0x53C]; //0x0054
	__int32 ET_TYPE; //0x0590 
	char pad_0x0594[0x360]; //0x0594
	__int8 allive; //0x08F4 
	char pad_0x08F5[0xB]; //0x08F5

	bool isAlive()
	{
		return (this->allive & 0x2) != 0;
	}

};//Size=0x0900

class clientinfo_t
{
public:
	char pad_0x0000[0x28]; //0x0000
	__int32 iClientNum; //0x0028 
	char cName[32]; //0x002C 
	__int32 iTeam; //0x004C 
	char pad_0x0050[0xE70]; //0x0050

};//Size=0x0EC0


class refdef_t
{
public:
	char pad_0x0000[0x4]; //0x0000
	__int32 iWidth; //0x0004 
	__int32 iHeight; //0x0008 
	char pad_0x000C[0x64]; //0x000C
	float fFovX; //0x0070 
	float fFovY; //0x0074 
	float N1B5B9CB5; //0x0078 
	char pad_0x007C[0x4]; //0x007C
	vec3 vecOrigin; //0x0080 
	char pad_0x008C[0x10]; //0x008C
	vec3 vecAxisX; //0x009C 
	vec3 vecAxisY; //0x00A8 
	vec3 vecAxisZ; //0x00B4 

};//Size=0x00C0
