#include "vec3.h"
#include <cmath>

vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


vec3 vec3::VectorSubtract(vec3 vec) const
{
	vec3 vektor = { x - vec.x, y - vec.y, z - vec.z };
	return vektor;
}

float vec3::DotProduct(vec3 vec) const
{
	return (x*vec.x + y*vec.y + z*vec.z);
}

float vec3::Vec3len() const
{
	return sqrt((x*x + y*y + z*z));
}

void vec3::VectorNormalize(vec3* pOUT) const
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

float vec3::GetDistance(vec3 end) const
{
	float X = x - end.x;
	float Y = y - end.y;
	float Z = z - end.z;

	return static_cast<float>(sqrt(X * X + Y * Y + Z * Z));
}
