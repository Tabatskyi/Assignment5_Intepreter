#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SyntaxHolder
{
public:
	SyntaxHolder();
	~SyntaxHolder() = default;

	string functionDefinition;
	string variableDefinition;
	map<string, unique_ptr<Function>> functionToClassMap;
};

