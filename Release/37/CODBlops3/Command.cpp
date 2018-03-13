#include "Command.h"

Command::Status Command::getStatus()
{
	return this->status;
}

void Command::setStatus(Command::Status _status)
{
	this->status = _status;
}

std::string Command::getExecutionMessage()
{
	return this->executionMessage;
}

void Command::setExecutionMessage(std::string _executionMessage)
{
	this->executionMessage = _executionMessage;
}

bool Command::getShouldPrint()
{
	return this->shouldPrint;
}

void Command::setShouldPrint(bool _shouldPrint)
{
	this->shouldPrint = _shouldPrint;
}