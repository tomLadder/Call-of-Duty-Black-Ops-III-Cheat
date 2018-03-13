#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Command.h"

class UnknownCommand : public Command
{
private:
	std::string cmdText;
public:
	UnknownCommand(std::string cmdText);

	virtual std::string getInstructionName();
	virtual std::string getInstruction();
	virtual void execute();
};