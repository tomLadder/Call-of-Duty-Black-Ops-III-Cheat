#include "vec2.h"
#include <cmath>

const double PI(3.14159265);

const double toDegrees(const double degree)
{
	return degree * 180.0 / PI;
}

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}


float vec2::GetAngleBetweenVector(vec2 vec)
{
	return toDegrees(atan((vec.y - this->y) / (vec.x - this->x)));
}

float vec2::GetLengthBetweenVector(vec2 vec)
{
	return sqrt((pow(this->x - vec.x, 2) + (pow(this->y - vec.y, 2))));
}