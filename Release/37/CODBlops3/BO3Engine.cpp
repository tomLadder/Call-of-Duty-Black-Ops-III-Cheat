#include "BO3Engine.h"

BO3Engine* BO3Engine::_instance = 0;

void BO3Engine::RegisterEngineTags()
{
	//Bones
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

vec3& BO3Engine::GetTagPos(entity_t* entity, long long tagName)
{
	float vec[7] = { 0,0,0,0,0,0,0 };
	pAimtarget_GetTagPos(0, entity, tagName, vec);
	vec3 vector = vec3(vec[0], vec[1], vec[2]);

	return vector;
}

entity_t* BO3Engine::GetEntity(int id)
{
	return (entity_t*)GetEntityProxy(0, id, this->proxyAddr, OFFCG_GetEntity);
}

clientinfo_t* BO3Engine::GetClientInfo(long long id)
{
	cg_t* cg = this->GetCGT(0);

	return (clientinfo_t*)((DWORD_PTR)cg + 0x2E78E8 + (0xEC0 * id));
}

cg_t* BO3Engine::GetCGT(int localClientNum)
{
	return (cg_t*)GetCGTProxy(localClientNum, this->proxyAddr, OFFGetCGT);
}

refdef_t* BO3Engine::GetRefDef()
{
	cg_t* cg = this->GetCGT(0);

	return (refdef_t*)((DWORD_PTR)cg + 0x131CB8);
}

long long BO3Engine::GetSRCPlacement()
{
	return srcPlace;
}

long long BO3Engine::RegisterShader(char* shadername)
{
	return pRegisterShader(shadername, 7, 1, 0xFFFFFFFF);
}

void BO3Engine::DrawStretchPicPhysical(float x, float y, float width, float height, float* color, long long material)
{
	pCL_DrawStretchPicPhysical(x, y, width, height, 0, 0, 1, 1, color, material);
}

void BO3Engine::DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, float* color, long long material)
{
	pCG_DrawRotatedPicPhysicalW(pGetScreenPlacement(0), x, y, 1, width, height, angle, color, material, 0);
}

int BO3Engine::TextWidth(char* text, long long font)
{
	return pR_TextWidth(0, text, 0x7FFFFFFF, font);
}

int BO3Engine::TextHeight(long long font)
{
	return pR_TextHeight(font);
}

void BO3Engine::AddCmdDrawText(const char* text, long long font, float x, float y, float xScale, float yScale, float rotation, const float* color)
{
	pR_AddCmdDrawText(text, 0x7FFFFFFF, font, x, y, xScale, yScale, rotation, color, 0);
}

long long BO3Engine::GetFont(int i)
{
	return pGetFont(0, i);
}
