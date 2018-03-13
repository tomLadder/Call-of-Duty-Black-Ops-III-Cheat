#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Esp.h"
#include "SDK.h"
#include "BO3Engine.h"
#include "CODMath.h"

class NameEsp : public Esp
{
public:
	void draw(entity_t* entity, clientinfo_t* clientinfo, bool isFriendly, bool isVisible);
};
