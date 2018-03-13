#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Command.h"
#include "CommandClear.h"
#include "CommandSet.h"
#include "UnknownCommand.h"

class CommandFactory
{
private:
	static CommandFactory* _commandFactory;
public:
	static inline CommandFactory* Instance()
	{
		if (_commandFactory == nullptr)
		{
			_commandFactory = new CommandFactory;
		}

		return _commandFactory;
	}

	Command* getCommand(std::string cmdText);
};
