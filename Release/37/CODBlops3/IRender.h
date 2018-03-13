#pragma once

class IRender
{
public:
	virtual ~IRender()
	{
	}

	virtual void Init() = 0;
	virtual void DrawRectangle(float x, float y, float width, float height, float* color) = 0;
	virtual void DrawRectangleFilled(float x, float y, float width, float height, float* color) = 0;
	virtual void DrawLine(float x1, float y1, float x2, float y2, float width, float* color) = 0;
	virtual void DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material) = 0;
};