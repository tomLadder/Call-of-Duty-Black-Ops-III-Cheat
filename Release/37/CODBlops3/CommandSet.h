#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Command.h"
#include <iostream>
#include <string>
#include <regex>

class CommandSet : public Command
{
private:
	std::string instrunctionName = "set";
	std::string parameter;
public:
	CommandSet(std::string cmdText);

	virtual std::string getInstructionName();
	virtual std::string getInstruction();
	virtual void execute();
	static bool isValid(std::string cmdText);
};