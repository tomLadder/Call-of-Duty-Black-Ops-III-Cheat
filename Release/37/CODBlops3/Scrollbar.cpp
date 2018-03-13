#include "Scrollbar.h"

Scrollbar::Scrollbar(float _x, float _y, float _width, float _height, Color* _colorBackground, Color* _colorBorder, Color* _colorElements, Color* _colorArrow)
{
	this->x = _x;
	this->y = _y;
	this->width = _width;
	this->height = _height;
	this->colorBackground = _colorBackground;
	this->colorBorder = _colorBorder;
	this->colorElements = _colorElements;
	this->colorArrow = _colorArrow;

	this->value = 0;
}

void Scrollbar::drawValueBar()
{
	float x = this->x + 4;
	float y = this->y + this->width + 2;
	float completeHeight = (((((this->y + this->height - this->width - 4) - (this->y + this->width)) - this->valueBarHeight) / this->maxValue) * this->value);
	BO3Render::getInstance()->DrawRectangleFilled(x, y + completeHeight, this->width - 8, this->valueBarHeight, this->colorBorder->toFloat());
}


void Scrollbar::drawArrow(float x, float y, float width, float height)
{
	BO3Render::getInstance()->DrawRectangleFilled(x, y, width, height, this->colorBorder->toFloat());
}

void Scrollbar::drawBackground()
{
	BO3Render::getInstance()->DrawRectangleFilled(this->x, this->y, this->width, this->height, this->colorBackground->toFloat());
	BO3Render::getInstance()->DrawBox(this->x, this->y, this->width, this->height, this->colorBorder->toFloat());

	this->drawArrow(this->x, this->y, this->width, this->width);
	this->drawArrow(this->x, this->y + this->height - this->width, this->width, this->width);

	this->drawValueBar();
}

void Scrollbar::draw()
{
	this->drawBackground();
}

void Scrollbar::setX(float _x)
{
	this->x = _x;
}

void Scrollbar::setY(float _y)
{
	this->y = _y;
}

void Scrollbar::setWidth(float _width)
{
	this->width = _width;
}

void Scrollbar::setHeight(float _height)
{
	this->height = _height;
}

void Scrollbar::setColorBackground(Color* color)
{
	this->colorBackground = color;
}

void Scrollbar::setColorBorder(Color* color)
{
	this->colorBorder = color;
}

void Scrollbar::setColorElements(Color* color)
{
	this->colorElements = color;
}

void Scrollbar::setColorArrow(Color* color)
{
	this->colorArrow = color;
}


void Scrollbar::setValue(int _value)
{
	if (_value < 0)
		this->value = 0;
	else if (_value > 100)
		this->value = 100;
	else
		this->value = _value;
}

int Scrollbar::getValue()
{
	return this->value;
}

void Scrollbar::setMaxValue(int _maxValue)
{
	this->maxValue = _maxValue;
}

int Scrollbar::getMaxValue()
{
	return this->maxValue;
}