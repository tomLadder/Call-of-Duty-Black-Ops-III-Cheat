#include "Rendering.h"

#define M_PI 3.14159265

void Rendering::Init()
{
	this->materialWhite = pRegisterShader("white", 3, 1, 0xFFFFFFFF);
	this->materialCompassping_enemy = pRegisterShader("compass_empcore_white", 3, 1, 0xFFFFFFFF);
	this->materialCompassping_friendly_mp = pRegisterShader("compass_cuav", 3, 1, 0xFFFFFFFF);
}

void Rendering::DrawBox(float x, float y, float width, float height, float* color)
{
	//Top
	pCL_DrawStretchPicPhysical(x, y, width, 4, 0, 0, 1, 1, color, this->materialWhite);
	//Left
	pCL_DrawStretchPicPhysical(x, y, 4, height, 0, 0, 1, 1, color, this->materialWhite);
	//Right
	pCL_DrawStretchPicPhysical(x + width - 4, y, 4, height, 0, 0, 1, 1, color, this->materialWhite);
	//Bottom
	pCL_DrawStretchPicPhysical(x, y + height, width, 4, 0, 0, 1, 1, color, this->materialWhite);
}

void Rendering::DrawField(float x, float y, float width, float height, float* color)
{
	pCL_DrawStretchPicPhysical(x, y, width, height, 0, 0, 1, 1, color, this->materialWhite);
}

void Rendering::DrawLine(float x1, float y1, float x2, float y2, float width, float* color)
{
	float l1 = x2 - x1, h = y2 - y1, l2 = sqrt(l1 * l1 + h * h);

	pCG_DrawRotatedPicPhysical(srcPlace, x1 + ((l1 - l2) / 2.f), y1 + (h / 2.f), l2, width, (180.f / M_PI * atan(h / l1)), color, materialWhite);
}

void Rendering::DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material)
{
	pCG_DrawRotatedPicPhysical(srcPlace, x, y, width, height, angle, color, material);
}