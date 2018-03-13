#include "BO3Render.h"

BO3Render* BO3Render::_instance = 0;

BO3Render::BO3Render()
{
	this->Init();
}

void BO3Render::Init()
{
	this->materialWhite = BO3Engine::getInstance()->RegisterShader("white");
	this->font = BO3Engine::getInstance()->GetFont(5);
}

void BO3Render::DrawRectangle(float x, float y, float width, float height, float* color)
{
	//Top
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y, width, 4, color, this->materialWhite);
	//Left
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y, 4, height, color, this->materialWhite);
	//Right
	BO3Engine::getInstance()->DrawStretchPicPhysical(x + width - 4, y, 4, height, color, this->materialWhite);
	//Bottom
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y + height, width, 4, color, this->materialWhite);
}

void BO3Render::DrawRectangleFilled(float x, float y, float width, float height, float* color)
{
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y, width, height, color, this->materialWhite);
}

void BO3Render::DrawLine(float x1, float y1, float x2, float y2, float width, float* color)
{
	float l1 = x2 - x1, h = y2 - y1, l2 = sqrt(l1 * l1 + h * h);

	BO3Engine::getInstance()->DrawRotatedPicPhysical(x1 + ((l1 - l2) / 2.f), y1 + (h / 2.f), l2, width, (180.f / M_PI * atan(h / l1)), color, materialWhite);
}

void BO3Render::DrawShader(float x, float y, float width, float height, float angle, float* color, __int64 material)
{
	BO3Engine::getInstance()->DrawRotatedPicPhysical(x, y, width, height, angle, color, material);
}

void BO3Render::DrawEngineText(float x, float y, float scale, char* text, float* color)
{
	BO3Engine::getInstance()->AddCmdDrawText(text, this->font, x, y, scale, scale, 0, color);
}

void BO3Render::DrawEngineTextFormatted(TextOrientation textOrientation, float x, float y, float width, float height, float scale, char* text, float* color)
{
	int widthFont = BO3Engine::getInstance()->TextWidth(text, this->font) * scale;
	int heightFont = BO3Engine::getInstance()->TextHeight(this->font) * scale;
	float textX, textY;
	switch (textOrientation)
	{
	case TOPLEFT:
		textX = x;
		textY = y + heightFont;
		break;
	case TOPRIGHT:
		textX = x + width - widthFont;
		textY = y + heightFont;
		break;
	case BOTTOMLEFT:
		textX = x;
		textY = y + height;
		break;
	case BOTTOMRIGHT:
		textX = x + width - widthFont;
		textY = y + heightFont + (height / 2 - heightFont / 2);
		break;
	case MIDDLELEFT:
		textX = x;
		textY = y + heightFont + (height / 2 - heightFont / 2);
		break;
	case MIDDLERIGHT:
		textX = x + width - widthFont;
		textY = y + heightFont + (height / 2 - heightFont / 2);
		break;
	case MIDDLE:
		textX = x + width / 2 - widthFont / 2;
		textY = y + heightFont + (height / 2 - heightFont / 2);
		break;
	}

	this->DrawEngineText(textX, textY, scale, text, color);
}

void BO3Render::DrawBox(float x, float y, float width, float height, float* color)
{
	//Top
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y, width, 2,color, this->materialWhite);
	//Left
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y, 2, height,color, this->materialWhite);
	//Right
	BO3Engine::getInstance()->DrawStretchPicPhysical(x + width - 2, y, 2, height, color, this->materialWhite);
	//Bottom
	BO3Engine::getInstance()->DrawStretchPicPhysical(x, y + height, width, 2, color, this->materialWhite);
}
