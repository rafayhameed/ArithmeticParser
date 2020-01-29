#pragma once
#include "Parser.h"
#include "evaluator.h"
class TwoStepParser
{
private:
	Parser parser;
	evaluator evaluator;
public:
	std::string calculate(std::string input);
	TwoStepParser();	
	~TwoStepParser();
};

