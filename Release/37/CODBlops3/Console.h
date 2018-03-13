#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include "BO3Render.h"
#include "CommandFactory.h"
#include "Command.h"
#include "ColorManager.h"
#include "Scrollbar.h"

class Console
{
private:
	std::vector<Command*> vecCommands;

	Color* colorBackGround;
	Color* colorBorder;
	Color* colorInputBox;
	Color* colorExecutionSucess;
	Color* colorExecutionFailed;
	Color* colorText;
	Color* colorPrint;
	Scrollbar* scrollbar;

	bool open = false;
	int count = 0;
	unsigned int maxChar = 0;
	float x, y, width, height;
	std::string buffer;
	std::string title;

	void drawInputBox();
	void drawBackGround();
	void drawBorder();
	void drawHeader();
	void drawScrollbar();
	void addText(std::string text, float* color, BO3Render::TextOrientation textOrientation);
	void drawExecutedCommands();

	static Console* _console;
public:
	static inline Console* Instance()
	{
		if (_console == nullptr)
		{
			_console = new Console;
		}

		return _console;
	}

	Console()
	{
		buffer = std::string(""); x = 10; y = 500; width = 500; height = 400; maxChar = 53;
		this->title = std::string("SyntheticCheats.com");
		this->vecCommands.clear();
		this->open = true;

		this->colorText = ColorManager::Instance()->getColorFromRGB(255.f, 255.f, 255.f, 255.f);
		this->colorBackGround = ColorManager::Instance()->getColorFromRGB(181.f, 179.f, 179.f, 127.5f);
		this->colorInputBox = ColorManager::Instance()->getColorFromRGB(93.f, 93.f, 93.f, 218.f);
		this->colorBorder = ColorManager::Instance()->getColorFromRGB(0.f, 127.f, 255.f, 255.f);
		this->colorPrint = ColorManager::Instance()->getColorFromRGB(0.f, 0.f, 0.f, 255.f);
		this->colorExecutionFailed = ColorManager::Instance()->getColorFromRGB(204.f, 51.f, 0.f, 255.f);
		this->colorExecutionSucess = ColorManager::Instance()->getColorFromRGB(0.f, 153.f, 0.f, 255.f);
		this->scrollbar = new Scrollbar(this->x + width - 30, this->y + 20, 20, this->height - 70.f, this->colorBackGround, this->colorBorder, this->colorExecutionSucess, ColorManager::Instance()->getColorFromRGB(0.f, 153.f, 0.f, 255.f));
	}


	void draw();
	void addKey(char keyCode);
	void eventScrollDown();
	void eventScrollUp();
	void clear();
	bool getOpen();
};
