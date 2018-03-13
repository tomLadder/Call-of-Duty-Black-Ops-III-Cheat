#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "CODEngine.h"
#include "GlobalVars.h"
#include <Tools.h>
#include "BO3Render.h"

extern "C" __int64 GetCGTProxy(int localClientNum, DWORD64 proxyAddr, DWORD64 cgtAddr);
extern "C" __int64 GetEntityProxy(int localClientNum, int id, DWORD64 proxyAddr, DWORD64 entityAddr);

class BO3Engine : public CODEngine
{
public:
	void RegisterEngineTags() override;
	vec3& GetTagPos(entity_t* entity, long long tagName) override;
	entity_t* GetEntity(int id) override;
	clientinfo_t* GetClientInfo(long long id) override;
	cg_t* GetCGT(int localClientNum) override;
	refdef_t* GetRefDef() override;
	long long GetSRCPlacement() override;
	long long RegisterShader(char* shadername) override;
	void DrawStretchPicPhysical(float x, float y, float width, float height, float* color, long long material);
	void DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, float* color, long long material);
	int TextWidth(char* text, long long font);
	int TextHeight(long long font);
	void AddCmdDrawText(const char *text, __int64 font, float x, float y, float xScale, float yScale, float rotation, const float *color);
	long long GetFont(int i);

	__forceinline static BO3Engine* getInstance()
	{
		if (!_instance)
			_instance = new BO3Engine();

		return _instance;
	}
private:
	static BO3Engine* _instance;
	DWORD64 proxyAddr = NULL;	
	BO3Engine() { proxyAddr = Tools::Memory::FindProxy(); std::cout << std::hex << proxyAddr << std::endl; }

	//Engine-Tags
	 __int64 j_helmet;
	 __int64 j_head;
	 __int64 j_neck;
	 __int64 j_shoulder_le;
	 __int64 j_elbow_le;
	 __int64 j_wrist_le;
	 __int64 j_shoulder_ri;
	 __int64 j_elbow_ri;
	 __int64 j_wrist_ri;
	 __int64 j_spineupper;
	 __int64 j_spinelower;
	 __int64 j_hip_le;
	 __int64 j_knee_le;
	 __int64 j_ankle_le;
	 __int64 j_hip_ri;
	 __int64 j_knee_ri;
	 __int64 j_ankle_ri;
};
