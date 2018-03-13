#pragma once
#include "Color.h"

class ColorManager
{
private:
	static ColorManager* _colorManager;
public:
	Color* white;
	Color* black;
	Color* red;
	Color* blue;
	Color* green;
	Color* yellow;
	Color* yellowgreen;
	Color* orange;
	Color* darkorange;

	static inline ColorManager* Instance() {
		if (_colorManager == nullptr) {
			_colorManager = new ColorManager;
			_colorManager->white = new Color(1.f, 1.f, 1.f, 1.f);
			_colorManager->black = new Color(0.f, 0.f, 0.f, 0.f);
			_colorManager->red = new Color(1.f, 0.f, 0.f, 1.f);
			_colorManager->blue = new Color(0.f, 0.f, 1.f, 1.f);
			_colorManager->green = new Color(0.f, 1.f, 0.f, 0);
			_colorManager->yellow = new Color(1, 1, 0, 1);
			_colorManager->yellowgreen = new Color(0.603922, 0.803922, 0.196078, 1);
			_colorManager->orange = new Color(1, 0.647059, 0, 1);
			_colorManager->darkorange = new Color(1, 0.54902, 0, 1.f);
		}
		return _colorManager;
	}

	Color* getColorFromRGB(float r, float g, float b, float t);
};