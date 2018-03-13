#pragma once
#include "GlobalVars.h"
#include <stdio.h>
#include <math.h>

class Rendering
{
private:
	__int64 materialWhite;
	__int64 materialCompassping_enemy;
	__int64 materialCompassping_friendly_mp;

	static Rendering* _rendering;
public:
	static Rendering* Instance();

	void Init();
	void DrawBox(float x, float y, float width, float height, float* color);
	void DrawField(float x, float y, float width, float height, float* color);
	void DrawLine(float x1, float y1, float x2, float y2, float width, float* color);
	void DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material);
};
