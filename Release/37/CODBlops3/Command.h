#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>

class Command
{
public:
	Command() { this->shouldPrint = true; }

	enum Status { SUCCESS, FAILED };

	virtual std::string getInstructionName() = 0;
	virtual std::string getInstruction() = 0;
	virtual void execute() = 0;
	Status getStatus();
	void setStatus(Status _status);
	std::string getExecutionMessage();
	bool getShouldPrint();
	void setShouldPrint(bool _shouldPrint);
	void setExecutionMessage(std::string _executionMessage);
private:
	Status status;
	std::string executionMessage;
	bool shouldPrint;
};
