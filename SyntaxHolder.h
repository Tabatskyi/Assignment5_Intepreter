#pragma once
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class SyntaxHolder
{
public:
	SyntaxHolder();
	~SyntaxHolder() = default;

	string functionDefinition;
	string variableDefinition;
	array<string, 4> reservedFunctionNames;
};

