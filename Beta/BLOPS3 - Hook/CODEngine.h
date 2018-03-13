#pragma once
#include "Engine.h"
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

	static clientinfo_t* CODEngine::GetClientInfo(__int64 index)
	{
		for (int i = 0;i < 12;i++)
		{
			if (index == clientinfo[i].iClientNumber)
				return &clientinfo[i];
		}

		return nullptr;
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
};
