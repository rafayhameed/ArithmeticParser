#ifndef evaluator_HPP
#define evaluator_HPP
#include "pch.h"
#include "Parser.h"

class evaluator
{
public:
	evaluator();
	~evaluator();
	int ast_evaluation(Node* ast);

private:
	bool is_number(const std::string &s);
};
#endif
