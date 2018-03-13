#include "Console.h"
#include <iostream>

Console* Console::_console = nullptr;

void Console::drawHeader()
{
	std::string str(this->maxChar + 3, '=');
	this->addText(str.c_str(), this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
	this->addText("Game:    Call of Duty - Black Ops 1", this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
	this->addText("Version: 1.0", this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
	this->addText("Coder:   teohasele", this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
	this->addText(str.c_str(), this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
}

void Console::drawBackGround()
{
	BO3Render::getInstance()->DrawRectangleFilled(this->x, this->y, this->width, this->height, this->colorBackGround->toFloat());
	BO3Render::getInstance()->DrawEngineTextFormatted(BO3Render::MIDDLE, this->x, this->y, this->width, 20, .87f, (char*)this->title.c_str(), this->colorText->toFloat());
	BO3Render::getInstance()->DrawRectangleFilled(this->x + 10.f, this->y + 20.f, this->width - 45.f, this->height - 70.f, ColorManager::Instance()->white->toFloat());
}

void Console::drawBorder()
{
	BO3Render::getInstance()->DrawBox(this->x, this->y, this->width, this->height, this->colorBorder->toFloat());
	BO3Render::getInstance()->DrawBox(this->x + 10.f, this->y + 20.f, this->width - 45.f, this->height - 70.f, this->colorBorder->toFloat());
}

void Console::drawInputBox()
{
	BO3Render::getInstance()->DrawRectangleFilled(this->x + 10.f, this->y + this->height - 40.f, this->width - 20.f, 30.f, this->colorInputBox->toFloat());
	BO3Render::getInstance()->DrawEngineTextFormatted(BO3Render::MIDDLELEFT, this->x + 15, this->y + this->height - 40, this->width - 25, 30, .87f, (char*)("> " + this->buffer).c_str(), this->colorText->toFloat());
}

void Console::drawScrollbar()
{
	this->scrollbar->draw();
}

void Console::addText(std::string text, float* color, BO3Render::TextOrientation textOrientation)
{
	float fontHeight = (float)BO3Engine::getInstance()->TextHeight(BO3Render::getInstance()->font);
	float scale = .87f;

	this->count++;
	int realCount = this->count - this->scrollbar->getValue() - 1;
	if (this->count - 1 >= this->scrollbar->getValue() && (this->y + 20.f + ((fontHeight + 4.f) * scale * realCount) + fontHeight * scale) < (this->y + 20.f + this->height - 70.f))
	{
		BO3Render::getInstance()->DrawEngineTextFormatted(textOrientation, this->x + 15.f, this->y + 20.f + ((fontHeight + 4.f) * scale * realCount), this->width - 50.f, fontHeight * scale, scale, (char*)text.c_str(), color);
	}
}

void Console::drawExecutedCommands()
{
	this->drawHeader();
	for (unsigned int i = 0; i < this->vecCommands.size(); ++i)
	{
		Command* currentCMD = this->vecCommands[i];
		if (currentCMD->getShouldPrint())
		{
			switch (currentCMD->getStatus())
			{
			case Command::SUCCESS:
				this->addText("> " + currentCMD->getInstruction(), this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
				this->addText("  ->" + currentCMD->getExecutionMessage(), this->colorExecutionSucess->toFloat(), BO3Render::MIDDLELEFT);
				break;
			case Command::FAILED:
				this->addText("> " + currentCMD->getInstruction(), this->colorPrint->toFloat(), BO3Render::MIDDLELEFT);
				this->addText("  ->" + currentCMD->getExecutionMessage(), this->colorExecutionFailed->toFloat(), BO3Render::MIDDLELEFT);
				break;
			}
		}
	}
}

void Console::draw()
{
	if (this->open)
	{
		this->count = 0;

		this->drawBackGround();
		this->drawBorder();
		this->drawInputBox();
		this->drawExecutedCommands();
		this->drawScrollbar();
	}
}

void Console::addKey(char key)
{
	if (key == VK_INSERT)
	{
		this->open = !this->open;
	}
	else if (this->open)
	{
		if (key == VK_RETURN)
		{
			Command* cmd = CommandFactory::Instance()->getCommand(this->buffer);
			cmd->execute();
			vecCommands.push_back(cmd);
			this->buffer.clear();
			this->scrollbar->setValue((vecCommands.size() * 2) - 10);
			this->scrollbar->setMaxValue((vecCommands.size() * 2) - 10);
		}
		else if (key == VK_BACK && this->buffer.size() != 0)
		{
			this->buffer = this->buffer.erase(this->buffer.size() - 1, 1);
		}
		else if (key != VK_BACK && this->buffer.size() < maxChar)
			this->buffer.push_back(key);
	}
}

void Console::clear()
{
	this->vecCommands.clear();
	this->scrollbar->setValue(0);
	this->scrollbar->setMaxValue(0);
}

bool Console::getOpen()
{
	return this->open;
}

void Console::eventScrollDown()
{
	if (this->scrollbar->getValue() < this->scrollbar->getMaxValue())
		this->scrollbar->setValue(this->scrollbar->getValue() + 1);
}

void Console::eventScrollUp()
{
	if (this->scrollbar->getValue() > 0)
		this->scrollbar->setValue(this->scrollbar->getValue() - 1);
}