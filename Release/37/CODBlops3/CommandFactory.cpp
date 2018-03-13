#include "CommandFactory.h"

CommandFactory* CommandFactory::_commandFactory = nullptr;

Command* CommandFactory::getCommand(std::string cmdText)
{
	Command* cmd = nullptr;
	if (CommandClear::isValid(cmdText))
		cmd = new CommandClear();
	else if (CommandSet::isValid(cmdText))
		cmd = new CommandSet(cmdText);
	else
		cmd = new UnknownCommand(cmdText);

	return cmd;
}