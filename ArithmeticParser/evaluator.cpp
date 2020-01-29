#include "pch.h"
#include "evaluator.h"

evaluator::evaluator() {}
evaluator::~evaluator() {}

bool evaluator::is_number(const std::string &s)
{
	// Replace `m` for a `-`
	std::string tmp = std::regex_replace(s, std::regex("m"), "-");

	// Check if string format is a number
	if (std::regex_match(tmp, std::regex("[-+]?\\d+\\.?\\d*")))
	{
		return true;
	}
	return false;
}

int evaluator::ast_evaluation(Node* ast)
{
	// Check null
	if (ast == nullptr)
	{
		throw std::invalid_argument("Invalid AST: nullptr");
	}

	// Evaluation
	std::string s = ast->value;

	if (is_number(s))
	{
		// Handling negative numbers
		if (s.substr(0, 1) == "m")
		{
			s = "-" + s.substr(1, s.length());
		}
		return std::stof(s);
	}
	else
	{
		int op1 = ast_evaluation(ast->left);
		int op2 = ast_evaluation(ast->right);

		if (s == "+") { return op1 + op2; }
		else if (s == "-") { return op1 - op2; }
		else if (s == "*") { return op1 * op2; }
		else if (s == "/") { return op1 / op2; }
	}
	delete ast;
}
