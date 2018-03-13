#include "CommandSet.h"

CommandSet::CommandSet(std::string cmdText)
{
	std::regex reg = std::regex("(set )(.*)");
	std::smatch sm;
	std::regex_match(cmdText, sm, reg);
	if (sm.size() > 0)
		this->parameter = cmdText.substr(this->instrunctionName.size() + 1);
}

std::string CommandSet::getInstructionName()
{
	return this->instrunctionName;
}

std::string CommandSet::getInstruction()
{
	return this->instrunctionName + " " + this->parameter;
}

void CommandSet::execute()
{

}

bool CommandSet::isValid(std::string cmdText)
{
	std::regex pattern = std::regex("(set )(.*)");
	std::smatch sm;
	std::regex_match(cmdText, sm, pattern);
	return sm.size() > 0;
}