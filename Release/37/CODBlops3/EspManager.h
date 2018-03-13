#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "BO3Render.h"
#include "BO3Engine.h"
#include "NameEsp.h"
#include "SDK.h"
#include "ColorManager.h"

class EspManager
{
private:
	NameEsp* nameEsp;
	static EspManager* _espManager;
public:
	bool nameEsp_enabled;

	static inline EspManager* Instance() {
		if (_espManager == nullptr) {
			_espManager = new EspManager;
			_espManager->nameEsp = new NameEsp;
		}
		return _espManager;
	}

	EspManager()
	{
		this->nameEsp_enabled = true;
		this->nameEsp->setColorInVisibleFriendly(ColorManager::Instance()->yellowgreen);
		this->nameEsp->setColorInVisibleEnemy(ColorManager::Instance()->yellow);
		this->nameEsp->setColorVisibleFriendly(ColorManager::Instance()->green);
		this->nameEsp->setColorVisbleEnemy(ColorManager::Instance()->darkorange);
	}

	void draw();
};
