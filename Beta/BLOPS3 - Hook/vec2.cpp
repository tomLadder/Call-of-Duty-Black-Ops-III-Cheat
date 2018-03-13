#include "vec2.h"

const double PI(3.14159265);

const double toDegrees(const double degree)
{
	return degree * 180.0/PI;
}

float vec2_t::GetAngleBetweenVector(vec2_t vec)
{
	return toDegrees(atan((vec.y - this->y) / (vec.x - this->x)));
}

float vec2_t::GetLengthBetweenVector(vec2_t vec)
{
	return sqrt((pow(this->x - vec.x, 2) + (pow(this->y - vec.y, 2))));
}