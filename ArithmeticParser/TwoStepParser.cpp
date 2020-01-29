#include "pch.h"
#include "TwoStepParser.h"


std::string TwoStepParser::calculate(std::string input)
{
	std::string result;
	if (parser.parsing(input)) {
		
		result= std::to_string(evaluator.ast_evaluation(parser.get_ast()));
	}
	else {
		result = "invalid";
	}
	return result;
}

TwoStepParser::TwoStepParser()
{
}


TwoStepParser::~TwoStepParser()
{
}
