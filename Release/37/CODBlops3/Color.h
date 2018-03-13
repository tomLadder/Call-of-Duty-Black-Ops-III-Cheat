#pragma once

class Color
{
	float r, g, b, t;
public:
	Color(float _r, float _g, float _b, float _t) { this->r = _r; this->g = _g; this->b = _b; this->t = _t; }
	float* toFloat();
};