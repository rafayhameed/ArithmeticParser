#include "pch.h"
#include "OneStepParser.h"



int OneStepParser::priority(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

int OneStepParser::operations(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

std::string OneStepParser::calculate(std::string input)
{
	std::string result;
	int evalRes = evaluate(input);
	if (evalRes != -1) {

		result = std::to_string(evalRes);
	}
	else {
		result = "invalid";
	}
	return result;
}

int OneStepParser::evaluate(std::string tokens) {
	int i;
	std::stack <int> values;
	std::stack <char> ops;

	for (i = 0; i < tokens.length(); i++) {
		if (tokens[i] == ' ')
			continue;
		else if (tokens[i] == '(') {
			ops.push(tokens[i]);
		}
		else if (isdigit(tokens[i])) {
			int val = 0;
			bool found = false;
			int k = i;
			while (k < tokens.length() &&
				isdigit(tokens[k]))
			{
				if (found) {
					return -1;
				}
				val = (tokens[i] - '0');
				k++;
				found = true;
			}

			values.push(val);
		}
		else if (tokens[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(operations(val1, val2, op));
			}
			if (!ops.empty())
				ops.pop();
		}
		else if (priority(tokens[i]) > 0)
		{
			while (!ops.empty() && priority(ops.top())
				>= priority(tokens[i])) {
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(operations(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
		else {
			return -1;
		}
	}
	while (!ops.empty() && values.size() > 1) {
		int val2 = values.top();
		values.pop();

		int val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(operations(val1, val2, op));
	}
	if (!ops.empty()) {
		return -1;
	}
	return values.top();
}
