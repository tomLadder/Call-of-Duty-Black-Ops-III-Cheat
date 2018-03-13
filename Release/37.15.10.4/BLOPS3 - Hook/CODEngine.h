#pragma once
#include "SDK.h"
#include "GlobalVars.h"

class CODEngine
{
public:
	static void CODEngine::RegisterTags()
	{
		j_helmet = pRegisterTag("j_helmet");
		j_head = pRegisterTag("j_head");
		j_neck = pRegisterTag("j_neck");
		j_shoulder_le = pRegisterTag("j_shoulder_le");
		j_elbow_le = pRegisterTag("j_elbow_le");
		j_wrist_le = pRegisterTag("j_wrist_le");
		j_shoulder_ri = pRegisterTag("j_shoulder_ri");
		j_elbow_ri = pRegisterTag("j_elbow_ri");
		j_wrist_ri = pRegisterTag("j_wrist_ri");
		j_spineupper = pRegisterTag("j_spineupper");
		j_spinelower = pRegisterTag("j_spinelower");
		j_hip_le = pRegisterTag("j_hip_le");
		j_knee_le = pRegisterTag("j_knee_le");
		j_ankle_le = pRegisterTag("j_ankle_le");
		j_hip_ri = pRegisterTag("j_hip_ri");
		j_knee_ri = pRegisterTag("j_knee_ri");
		j_ankle_ri = pRegisterTag("j_ankle_ri");
	}

	static vec3_t CODEngine::GetTagPos(entity_t* entity, __int64 tagName)
	{
		float vec[7] = { 0,0,0,0,0,0,0 };
		pAimtarget_GetTagPos(0, entity, tagName, vec);
		vec3_t vector;
		vector.x = vec[0];
		vector.y = vec[1];
		vector.z = vec[2];

		return vector;
	}

	static entity_t* CODEngine::GetEntity(int id)
	{
		return (entity_t*)(pCG_GetEntity(0, id));
	}

	static clientinfo_t* CODEngine::GetClientInfo(__int64 id) 
	{
		return (clientinfo_t*)((DWORD64)GetCGT() + 0x2E6B88 + (0xEB0 * id));
	}

	static cg_t* CODEngine::GetCGT() 
	{
		return (cg_t*)pGetCGT(0);
	}

	static refdef_t* CODEngine::GetRefDef() 
	{
		return(refdef_t*)0x0;
	}

	static __int64 CODEngine::GetSRCPlacement() 
	{
		return (__int64)0x0;
	}

	static __int64 RegisterShader(char* shadername) 
	{
		return pRegisterShader(shadername, 3, 1, 0xFFFFFFFF);
	}
};
