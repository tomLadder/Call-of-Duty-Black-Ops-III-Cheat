#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "vec2.h"
#include "vec3.h"
#include "BO3Engine.h"

class CODMath
{
private:
	static CODMath* _CODMath;
public:
	static inline CODMath* getInstance() {
		if (_CODMath == nullptr) {
			_CODMath = new CODMath;
		}
		return _CODMath;
	}

	bool WorldToScreen(vec3 world, float *x, float *y);
};