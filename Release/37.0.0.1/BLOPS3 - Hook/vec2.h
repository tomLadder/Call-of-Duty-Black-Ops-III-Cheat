#include <math.h>
#pragma once

class vec2_t
{
public:
	float GetAngleBetweenVector(vec2_t vec);
	float GetLengthBetweenVector(vec2_t vec);

	float x, y;
};
