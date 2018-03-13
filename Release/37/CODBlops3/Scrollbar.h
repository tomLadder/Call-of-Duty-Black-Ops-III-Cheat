#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Color.h"
#include "BO3Render.h"
#include <iostream>

class Scrollbar
{
private:
	Color* colorBackground;
	Color* colorBorder;
	Color* colorElements;
	Color* colorArrow;

	void drawValueBar();
	void drawArrow(float x, float y, float width, float height);
	void drawBackground();

	float x, y, width, height;
	int value, maxValue;
	float valueBarHeight = 40;
public:
	Scrollbar(float _x, float _y, float _width, float _height, Color* _colorBackground, Color* _colorBorder, Color* _colorElements, Color* _colorArrow);
	void draw();

	void setX(float _x);
	void setY(float _y);
	void setWidth(float _width);
	void setHeight(float _height);
	void setColorBackground(Color* color);
	void setColorBorder(Color* color);
	void setColorElements(Color* color);
	void setColorArrow(Color* color);
	void setValue(int _value);
	int getValue();
	void setMaxValue(int _maxValue);
	int getMaxValue();
};
