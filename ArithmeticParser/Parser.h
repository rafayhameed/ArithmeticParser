#ifndef Parser_HPP
#define Parser_HPP
#include "pch.h"
#include "Node.h"
#include <iostream>

class Parser
{
public:
	Parser();
	~Parser();
	bool parsing(std::string line);
	Node* get_ast();

private:
	std::stack<std::string> operators;
	std::string line;
	bool validate();	
	char cc;
	std::string s;
	std::stack<std::string> rpn;
	std::stack<Node*> ast_stack;
};
#endif
