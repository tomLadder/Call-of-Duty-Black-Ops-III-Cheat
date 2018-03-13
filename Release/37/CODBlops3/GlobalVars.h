#pragma once
#include "SDK.h"

//Defines
#define M_PI 3.14159265

//Offsets
#define OFFCG_Draw2D 0x1400C2F00
#define OFFCG_DrawRotatedPicPhysicalW 0x1400D1820
#define OFFCL_DrawStretchPicPhysical  0x1401AC5F0
#define OFFGetScreenPlacement 0x1401DB660
#define OFFAimTarget_GetTagPos 0x0
#define OFFRegisterShader 0x14041E7E0
#define OFFRegisterTag 0x1401828C0  //Interesting function: sub_140259030
#define OFFGetCGT 0x140033140
#define OFFCG_GetEntity 0x140032530
#define OFFR_RegisterFont 0x1403F4FD0
#define OFFR_AddCmdDrawText 0x140422B50
#define OFFR_TextWidth 0x1403F51D0
#define OFFR_TextHeight 0x1403F4FF0
#define OFFGetFont 0x1406EDD30

//Refdef
//WorldPosToScreenPos -> ida search for "%s %im"

//Typedefs
typedef int(*CG_Draw2D)(int localClientNum);
static CG_Draw2D pCG_Draw2D;

typedef void(*CG_DrawRotatedPicPhysicalW)(__int64 scrPlace, float x, float y, float w, float width, float height, float angle, float* color, __int64 material, __int64 unkn);
static CG_DrawRotatedPicPhysicalW pCG_DrawRotatedPicPhysicalW = (CG_DrawRotatedPicPhysicalW)(OFFCG_DrawRotatedPicPhysicalW);

typedef __int64(*GetScreenPlacement)(int localClientNum);
static GetScreenPlacement pGetScreenPlacement = (GetScreenPlacement)(OFFGetScreenPlacement);

typedef void(*CL_DrawStretchPicPhysical)(float x, float y, float w, float h, float a5, float a6, float a7, float a8, float* color, __int64 material);
static CL_DrawStretchPicPhysical pCL_DrawStretchPicPhysical = (CL_DrawStretchPicPhysical)(OFFCL_DrawStretchPicPhysical);

typedef int(*Aimtarget_GetTagPos)(int localClientNum, entity_t* entity, __int64 tagName, float* pos);
static Aimtarget_GetTagPos pAimtarget_GetTagPos = (Aimtarget_GetTagPos)(OFFAimTarget_GetTagPos);

typedef __int64(*RegisterShader)(char* shadername, int num, unsigned int num2, unsigned int num3);
static RegisterShader pRegisterShader = (RegisterShader)OFFRegisterShader;

typedef __int64(*RegisterTag)(char* tagName);
static RegisterTag pRegisterTag = (RegisterTag)OFFRegisterTag;

typedef cg_t*(*GetCGT)(int localClientNum);
static GetCGT pGetCGT = (GetCGT)OFFGetCGT;

typedef entity_t* (*CG_GetEntity)(int a1, int idx);
static CG_GetEntity pCG_GetEntity = (CG_GetEntity)OFFCG_GetEntity;

typedef __int64(*R_RegisterFont)(const char *name, int imageTrack);
static R_RegisterFont pR_RegisterFont = (R_RegisterFont)OFFR_RegisterFont;

typedef void(*R_AddCmdDrawText)(const char *text, int maxChars, __int64 font, float x, float y, float xScale, float yScale, float rotation, const float *color, int style);
static R_AddCmdDrawText pR_AddCmdDrawText = (R_AddCmdDrawText)OFFR_AddCmdDrawText;

typedef __int32(* R_TextWidth)(int localClientNum, char* text, int maxChars, __int64 font);
static R_TextWidth pR_TextWidth = (R_TextWidth)OFFR_TextWidth;

typedef __int32(* R_TextHeight)(__int64 font);
static R_TextHeight pR_TextHeight = (R_TextHeight)OFFR_TextHeight;

typedef __int64(*GetFont)(__int64 unkn, int num);
static GetFont pGetFont = (GetFont)OFFGetFont;

static __int64 srcPlace = 0x143498590;