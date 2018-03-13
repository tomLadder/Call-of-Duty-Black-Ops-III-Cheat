#pragma once
#include "Console.h"
#include "Rendering.h"

class Console
{
private:
	float x, y, width, height;

	void Init(float _x, float _y, float _width, float _height);

	static Console* _console;
public:
	static Console* Instance();
	void Update();
};
