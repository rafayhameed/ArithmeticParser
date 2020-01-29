#include "pch.h"
#ifndef PARSER_HPP
#define PARSER_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <stack>
#include <regex>

class Node
{
public:
	Node() {

	}
	Node(const std::string value) : value(value)
	{
	}
	Node(const std::string value, Node* left, Node* right)
		: value(value)
		, left(left)
		, right(right)
	{
	}
	Node& operator=(const Node &b)
	{
		value = b.value;
		left = b.left;
		right = b.right;
	}

	std::string value = "";
	Node *left = nullptr;
	Node *right = nullptr;
};
#endif
