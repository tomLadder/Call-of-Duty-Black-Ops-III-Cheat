#pragma once
#include "Rendering.h"

class Menu
{
private:
	float x, y, width, height;

	void Init(float _x, float _y, float _width, float _height);

	static Menu* _menu;
public:
	static Menu* Instance();
	void Update();
};
