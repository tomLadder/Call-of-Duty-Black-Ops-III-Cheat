#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <math.h>

class vec3
{
public:
	float x, y, z;

	vec3();
	vec3(float x, float y, float z);
	vec3 VectorSubtract(vec3 vec) const;
	float DotProduct(vec3 vec) const;
	float Vec3len() const;
	void VectorNormalize(vec3* pOUT) const;
	float GetDistance(vec3 end) const;
};