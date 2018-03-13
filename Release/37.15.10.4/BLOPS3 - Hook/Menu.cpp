#include "Menu.h"

Menu* Menu::_menu = 0;

Menu* Menu::Instance() {
	if (_menu == nullptr) {
		_menu = new Menu();
	}
	return _menu;
}

void Menu::Init(float _x, float _y, float _width, float _height) {
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
}

void Menu::Update() {
	float color[4] = { 1.f, 0.64f, 0.f, 1.f };
	Rendering::Instance()->DrawField(100, 150, 300, 250, color);
}