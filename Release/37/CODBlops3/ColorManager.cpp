#include "ColorManager.h"

ColorManager* ColorManager::_colorManager = nullptr;

Color* ColorManager::getColorFromRGB(float r, float g, float b, float t)
{
	return new Color((1.f / 255.f) * r, (1.f / 255.f) * g, (1.f / 255.f) * b, (1.f / 255.f) * t);
}