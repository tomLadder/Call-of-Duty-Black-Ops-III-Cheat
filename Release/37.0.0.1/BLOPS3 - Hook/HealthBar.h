#pragma once
#include "GlobalVars.h"
#include "Rendering.h"

class HealthBar
{
private:
	float HealthBarSurroundColor[4] = { 0.20f, 0.60f, 1.0f, 1.0f };
	float HealthBarBackGroundColor[4] = { 0.82f, 0.82f, 0.82f, 0.7f };

	float HealthBarColor90To100[4] = { 0.f, 1.f, 0.f, 1.f };
	float HealthBarColor80To90[4] = { 0.f, 8.f, 0.f, 1.f };
	float HealthBarColor70To80[4] = { 0.f, 6.f, 0.f, 1.f };
	float HealthBarColor60To70[4] = { 0.f, 4.f, 0.f, 1.f };
	float HealthBarColor50To60[4] = { 1.f, 1.f, 0.f, 1.f };
	float HealthBarColor40To50[4] = { 1.f, 0.8f, 1.f, 1.f };
	float HealthBarColor30To40[4] = { 1.f, 0.6f, 1.f, 1.f };
	float HealthBarColor20To30[4] = { 1.f, 0.4f, 1.f, 1.f };
	float HealthBarColor10To20[4] = { 0.7f, 0.f, 0.f, 1.f };
	float HealthBarColor0To10[4] = { 1.f, 0.f, 0.f, 1.f };

	float width = 300;
	float height = 50;
public:
	void Draw();
};
