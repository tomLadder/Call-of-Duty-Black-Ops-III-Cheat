#pragma once
#include "Engine.h"
#include "Rendering.h"

#define OFFCG_Draw2D 0x1400C28D0
#define OFFCL_WritePacket 0x14018A5C0
#define OFFCL_GetCurrentCmdNumber 0x140182C60
#define OFFCL_GetUserCmd 0x1401833F0
#define OFFCG_DrawRotatedPicPhysical 0x1400D3340
#define OFFCL_DrawStretchPicPhysical 0x140404DA0
#define OFFR_AddCmdDrawText 0x1403A8800
#define OFFR_RegisterFont 0x140383F50
#define OFFRegisterShader 0x140400F20
#define OFFRegisterTag 0x1402CC420
#define OFFAimTarget_GetTagPos 0x140030990
#define OFFBG_WeaponFireRecoil 0x140710270
//0x43560ca0

typedef int(*CG_Draw2D)(int localClientNum);

typedef void(*CL_WritePacket)(int localClientNum);
typedef int(*CL_GetCurrentCmdNumber)(int localClientNum);
typedef void(*CL_GetUserCmd)(int localClientNum, int cmdNumber, usercmd_t *cmd);

typedef void(*CG_DrawRotatedPicPhysical)(__int64 scrPlace, float x, float y, float width, float height, float angle, float* color, __int64 material);
typedef void(*CL_DrawStretchPicPhysical)(float x, float y, float w, float h, float a5, float a6, float a7, float a8, float* color, __int64 material);
typedef void(*R_AddCmdDrawText)(int maxChars, char* text, __int64 font, float x, float y, float xScale, float yScale, float rotation, float* color, int style);
typedef __int64(*R_RegisterFont)(char* name);
typedef __int64(*RegisterShader)(char* shadername, int num, unsigned int num2, unsigned int num3);
typedef __int64(*RegisterTag)(char* tagName);

typedef int(*Aimtarget_GetTagPos)(int localClientNum, entity_t* entity, __int64 tagName, float* pos);
typedef __int64(*BG_WeaponFireRecoil)(double val, void* ps, float* recoilSpeed, float* kickaVel);

static CG_Draw2D pCG_Draw2D;
static CL_WritePacket pCL_WritePacket;
static CL_GetCurrentCmdNumber pCL_GetCurrentCmdNumber = (CL_GetCurrentCmdNumber)OFFCL_GetCurrentCmdNumber;
static CL_GetUserCmd pCL_GetUserCmd = (CL_GetUserCmd)OFFCL_GetUserCmd;
static CL_DrawStretchPicPhysical pCL_DrawStretchPicPhysical = (CL_DrawStretchPicPhysical)OFFCL_DrawStretchPicPhysical;
static CG_DrawRotatedPicPhysical pCG_DrawRotatedPicPhysical = (CG_DrawRotatedPicPhysical)OFFCG_DrawRotatedPicPhysical;
static R_AddCmdDrawText pR_AddCmdDrawText = (R_AddCmdDrawText)OFFR_AddCmdDrawText;
static R_RegisterFont pR_RegisterFont = (R_RegisterFont)OFFR_RegisterFont;
static RegisterShader pRegisterShader = (RegisterShader)OFFRegisterShader;
static RegisterTag pRegisterTag = (RegisterTag)OFFRegisterTag;
static Aimtarget_GetTagPos pAimtarget_GetTagPos = (Aimtarget_GetTagPos)OFFAimTarget_GetTagPos;
static BG_WeaponFireRecoil pBG_WeaponFireRecoil = (BG_WeaponFireRecoil)OFFBG_WeaponFireRecoil;

static cg_t* cg = (cg_t*)0xE2C338680;
static cgs_t* cgs = (cgs_t*)0xE2C9CA780;
static entity_t* entities = (entity_t*)0xE2CBD1A00;
static clientinfo_t* clientinfo = (clientinfo_t*)0xE2C3C0400;
static refdef_t* refdef = (refdef_t*)0xE2C4676E0;

static __int64 srcPlace = 0x143560CA0;

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
