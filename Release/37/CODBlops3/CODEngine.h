#pragma once
#include "vec3.h"
#include "SDK.h"

class entity_t;

class CODEngine
{
public:
	virtual void RegisterEngineTags() = 0;
	virtual vec3& GetTagPos(entity_t* entity, __int64 tagName) = 0;
	virtual entity_t* GetEntity(int id) = 0;
	virtual clientinfo_t* GetClientInfo(__int64 id) = 0;
	virtual cg_t* GetCGT(int localClientNum) = 0;
	virtual refdef_t* GetRefDef() = 0;
	virtual __int64 GetSRCPlacement() = 0;
	virtual __int64 RegisterShader(char* shadername) = 0;
private:
};
