#include "Rendering.h"
#include "CODEngine.h"

#define M_PI 3.14159265

Rendering* Rendering::_rendering = 0;

Rendering* Rendering::Instance() {
	if (_rendering == nullptr) {
		_rendering = new Rendering;
		_rendering->Init();
	}
	return _rendering;
}

void Rendering::Init()
{
	this->materialWhite = CODEngine::RegisterShader("white");
	this->materialCompassping_enemy = CODEngine::RegisterShader("compass_empcore_white");
	this->materialCompassping_friendly_mp = CODEngine::RegisterShader("compass_cuav");
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
	float l1 = x2 - x1, h = y2 - y1, l2 = (float)sqrt(l1 * l1 + h * h);

	pCG_DrawRotatedPicPhysical(CODEngine::GetSRCPlacement(), x1 + ((l1 - l2) / 2.f), y1 + (h / 2.f), l2, width, (float)(180.f / M_PI * atan(h / l1)), color, this->materialWhite);
}

void Rendering::DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material)
{
	pCG_DrawRotatedPicPhysical(CODEngine::GetSRCPlacement(), x, y, width, height, angle, color, material);
}