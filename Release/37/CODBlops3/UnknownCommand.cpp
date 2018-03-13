#include "UnknownCommand.h"

UnknownCommand::UnknownCommand(std::string cmdText)
{
	this->cmdText = cmdText;
}

std::string UnknownCommand::getInstructionName()
{
	return "UNKNOWN";
}

std::string UnknownCommand::getInstruction()
{
	return this->cmdText;
}

void UnknownCommand::execute()
{
	Command::setStatus(Command::FAILED);
	Command::setExecutionMessage("command not found");
}