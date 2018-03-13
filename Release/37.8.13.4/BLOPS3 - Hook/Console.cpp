#include "Console.h"

Console* Console::_console = 0;

Console* Console::Instance() {
	if (_console == nullptr) {
		_console = new Console();
	}
	return _console;
}

void Console::Init(float _x, float _y, float _width, float _height) {
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}

void Console::Update() {
	float color[4] = { 1.f, 0.64f, 0.f, 1.f };
	Rendering::Instance()->DrawField(this->x, this->y, this->width, this->height, color);
}