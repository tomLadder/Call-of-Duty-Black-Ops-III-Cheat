#include <math.h>
#pragma once

class vec2
{
public:
	float x, y;

	vec2(float x, float y);
	float GetAngleBetweenVector(vec2 vec);
	float GetLengthBetweenVector(vec2 vec);
};
