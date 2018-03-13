#pragma once
#include "IRender.h"
#include "BO3Engine.h"

class BO3Render : IRender
{
public:
	__int64 materialWhite;
	__int64 font;

	enum TextOrientation { TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT, MIDDLELEFT, MIDDLERIGHT, MIDDLE };

	BO3Render();
	void Init() override;
	void DrawRectangle(float x, float y, float width, float height, float* color) override;
	void DrawRectangleFilled(float x, float y, float width, float height, float* color) override;
	void DrawLine(float x1, float y1, float x2, float y2, float width, float* color) override;
	void DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material) override;
	void DrawEngineText(float x, float y, float scale, char* text, float* color);
	void DrawEngineTextFormatted(TextOrientation textOrientation, float x, float y, float width, float height, float scale, char* text, float* color);
	void DrawBox(float x, float y, float width, float height, float* color);


	__forceinline static BO3Render* getInstance()
	{
		if (!_instance)
			_instance = new BO3Render();

		return _instance;
	}
private:
	static BO3Render* _instance;
};
