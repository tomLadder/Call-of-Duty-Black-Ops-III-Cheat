#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Command.h"
#include "Console.h"
#include <iostream>
#include <string>
#include <regex>

class CommandClear : public Command
{
private:
	std::string instructionName = "clear";
public:
	CommandClear();

	virtual std::string getInstructionName();
	virtual std::string getInstruction();
	virtual void execute();
	static bool isValid(std::string cmdText);
};