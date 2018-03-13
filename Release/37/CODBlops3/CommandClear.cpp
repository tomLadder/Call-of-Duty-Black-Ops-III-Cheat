#include "CommandClear.h"

CommandClear::CommandClear()
{
	Command::setShouldPrint(false);
}

std::string CommandClear::getInstructionName()
{
	return this->instructionName;
}

std::string CommandClear::getInstruction()
{
	return this->instructionName;
}

void CommandClear::execute()
{
	Console::Instance()->clear();
	Command::setStatus(Command::SUCCESS);
	Command::setExecutionMessage(std::string(""));
}

bool CommandClear::isValid(std::string cmdText)
{
	std::regex pattern = std::regex("(clear)");
	std::smatch sm;
	std::regex_match(cmdText, sm, pattern);
	return sm.size() > 0;
}