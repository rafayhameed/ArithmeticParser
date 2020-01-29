#pragma once
#include <iostream>
#include <stack> 
#include <string> 

class OneStepParser
{
private:
	int priority(char op);
	int operations(int a, int b, char op);
public:
	int evaluate(std::string input);
	std::string calculate(std::string input);
};

