#pragma once
#include "SDK.h"
#include "Rendering.h"

/*
Game Version: 37.15.10.4
*/

#define OFFCG_Draw2D 0x1400C2950						
#define OFFCG_DrawRotatedPicPhysical 0x1400D3430
#define OFFCL_DrawStretchPicPhysical 0x1401AC530
#define OFFRegisterShader 0x140401250
#define OFFRegisterTag 0x14031AE80
#define OFFAimTarget_GetTagPos 0x1400FBE80
#define OFFGetCGT 0x1400326C0
#define OFFCG_GetEntity 0x140032590

typedef int(*CG_Draw2D)(int localClientNum);
typedef void(*CG_DrawRotatedPicPhysical)(__int64 scrPlace, float x, float y, float width, float height, float angle, float* color, __int64 material);
typedef void(*CL_DrawStretchPicPhysical)(float x, float y, float w, float h, float a5, float a6, float a7, float a8, float* color, __int64 material);
typedef __int64(*RegisterShader)(char* shadername, int num, unsigned int num2, unsigned int num3);
typedef __int64(*RegisterTag)(char* tagName);
typedef int(*Aimtarget_GetTagPos)(__int64 unkn, entity_t* entity, __int64 tagName, float* pos);
typedef entity_t* (*CG_GetEntity)(int a1, int idx);
typedef cg_t*(*GetCGT)(int localClientNum);

static CG_Draw2D pCG_Draw2D;
static CL_DrawStretchPicPhysical pCL_DrawStretchPicPhysical = (CL_DrawStretchPicPhysical)OFFCL_DrawStretchPicPhysical;
static CG_DrawRotatedPicPhysical pCG_DrawRotatedPicPhysical = (CG_DrawRotatedPicPhysical)OFFCG_DrawRotatedPicPhysical;
static RegisterShader pRegisterShader = (RegisterShader)OFFRegisterShader;
static RegisterTag pRegisterTag = (RegisterTag)OFFRegisterTag;
static GetCGT pGetCGT = (GetCGT)OFFGetCGT;
static CG_GetEntity pCG_GetEntity = (CG_GetEntity)OFFCG_GetEntity;
static Aimtarget_GetTagPos pAimtarget_GetTagPos = (Aimtarget_GetTagPos)OFFAimTarget_GetTagPos;

static usercmd_t* usercmd;
static input_t input;

extern __int64 j_helmet;
extern __int64 j_head;
extern __int64 j_neck;
extern __int64 j_shoulder_le;
extern __int64 j_elbow_le;
extern __int64 j_wrist_le;
extern __int64 j_shoulder_ri;
extern __int64 j_elbow_ri;
extern __int64 j_wrist_ri;
extern __int64 j_spineupper;
extern __int64 j_spinelower;
extern __int64 j_hip_le;
extern __int64 j_knee_le;
extern __int64 j_ankle_le;
extern __int64 j_hip_ri;
extern __int64 j_knee_ri;
extern __int64 j_ankle_ri;


