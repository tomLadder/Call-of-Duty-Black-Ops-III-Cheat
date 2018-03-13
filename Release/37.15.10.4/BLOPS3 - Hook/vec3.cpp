#include "vec3.h"

vec3_t vec3_t::VectorSubtract(vec3_t vec)
{
	vec3_t vektor = { x - vec.x, y - vec.y, z - vec.z };
	return vektor;
}

float vec3_t::DotProduct(vec3_t vec)
{
	return (x*vec.x + y*vec.y + z*vec.z);
}

float vec3_t::Vec3len()
{
	return sqrt((x*x + y*y + z*z));
}

void vec3_t::VectorNormalize(vec3_t* pOUT)
{
	float mul = 1.0f;
	float len = Vec3len();

	if (len > 0.0005f)
	{
		mul = 1.0f / len;
	}

	pOUT->x = mul * x;
	pOUT->y = mul * y;
	pOUT->z = mul * z;
}

float vec3_t::GetDistance(vec3_t end)
{
	float X = x - end.x;
	float Y = y - end.y;
	float Z = z - end.z;

	return (float)sqrt(X * X + Y * Y + Z * Z);
}