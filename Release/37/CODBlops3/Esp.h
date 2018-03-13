#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Color.h"

class Esp
{
private:
	Color* colorVisibleEnemy;
	Color* colorVisibleFriendly;
	Color* colorInVisibleEnemy;
	Color* colorInVisibleFriendly;
public:
	void setColorVisbleEnemy(Color* _color)
	{
		colorVisibleEnemy = _color;
	}
	void setColorVisibleFriendly(Color* _color)
	{
		colorVisibleFriendly = _color;
	}
	void setColorInVisibleEnemy(Color* _color)
	{
		colorInVisibleEnemy = _color;
	}
	void setColorInVisibleFriendly(Color* _color)
	{
		colorInVisibleFriendly = _color;
	}

	__inline Color* getColorVisbleEnemy()
	{
		return this->colorVisibleEnemy;
	}
	__inline Color* getColorVisibleFriendly()
	{
		return this->colorVisibleFriendly;
	}
	__inline Color* getColorInVisibleEnemy()
	{
		return this->colorInVisibleEnemy;
	}
	__inline Color* getColorInVisibleFriendly()
	{
		return this->colorInVisibleFriendly;
	}
	__inline Color* getCorrectColor(bool isFriendly, bool isVisible)
	{
		Color* color = 0;
		if (isFriendly)
		{
			if (isVisible)
				color = this->colorVisibleFriendly;
			else
				color = this->colorInVisibleFriendly;
		}
		else
		{
			if (isVisible)
				color = this->colorVisibleEnemy;
			else
				color = this->colorInVisibleEnemy;
		}

		return color;
	}
};
