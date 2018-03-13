#pragma once
#include <math.h>

class vec3_t
{
public:
	float x, y, z;
	vec3_t VectorSubtract(vec3_t vec);
	float DotProduct(vec3_t vec);
	float Vec3len();
	void VectorNormalize(vec3_t* pOUT);
	float GetDistance(vec3_t end);
};