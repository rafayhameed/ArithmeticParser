#include "pch.h"
#include "Parser.h"

bool Parser::validate()
{
	std::istringstream input(line);
	bool num = false;
	bool brkt = false;
	bool neg = false;
	std::string op;
	int ind = -1;
	try {
		while (input >> cc)
		{
			ind++;
			std::string c(1, cc);
			if (cc == ' ')
				continue;			
			else if (isdigit(cc))
			{				
				if (num)
				{
					return false;
				}
				else
				{
					if (neg)
					{
						return false;
					}

					rpn.push(c);
					ast_stack.push(new Node(c));
					num = true;
				}
				brkt = false;
				num = true;
			}
			else if (c[0] == '+' || c[0] == '-' || c[0] == '/' || c[0] == '*')
			{
				num = false;				
				if (brkt && c == "-")
				{
					neg = true;
					continue;
				}
				else if (brkt && c == "+")
				{
					continue;
				}
				brkt = false;
			
				while (!operators.empty() && (operators.top()[0] == '/' || operators.top()[0] == '*'))
				{
					op = operators.top();
					rpn.push(op);
					operators.pop();

					Node *op2 = ast_stack.top();
					ast_stack.pop();
					Node *op1 = ast_stack.top();
					ast_stack.pop();

					ast_stack.push(new Node(op, op1, op2));

				}
				operators.push(c);
			}
			
			else if (cc == '(')
			{
				num = false;
				brkt = true;
				operators.push(c);
			}
			
			else if (cc == ')')
			{
				num = false;
				while (!operators.empty() &&
					!(operators.top()[0] == '('))
				{					
					op = operators.top();
					rpn.push(op);
					operators.pop();

					Node *op2 = ast_stack.top();
					ast_stack.pop();
					Node *op1 = ast_stack.top();
					ast_stack.pop();

					ast_stack.push(new Node(op, op1, op2));
				}
			
				if (operators.empty())
				{
					return false;
				}

				operators.pop();
			}
			else if (c == ".")
			{
				return false;
			}
		}

		while (!operators.empty())
		{			
			std::string t = operators.top();			
			if ((t[0] == '(') ||
				(t[0] == ')'))
			{
				return false;
			}
			op = operators.top();
			rpn.push(op);
			operators.pop();
			if (ast_stack.size() > 1) {
				Node *op2 = ast_stack.top();
				ast_stack.pop();
				Node *op1 = ast_stack.top();
				ast_stack.pop();

				ast_stack.push(new Node(op, op1, op2));
			}
			else {
				return false;
			}
			
		}
		
		std::stack<std::string> oo;
		while (!rpn.empty())
		{
			oo.push(rpn.top());
			rpn.pop();
		}
		rpn = oo;
		return true;
	}
	catch (const std::exception& exp) {
		std::cout << "exception " << exp.what()<<std::endl;
		return false;
	}
}

bool Parser::parsing(std::string input)
{
	line = input;
	if (!validate()) {
		while (!ast_stack.empty()) {
			Node* nod = ast_stack.top();
			ast_stack.pop();
			delete nod;
		}
		return false;
	}
	return true;
}

Parser::Parser()
{
}

Parser::~Parser() {}

Node* Parser::get_ast()
{
	return this->ast_stack.top();
}

