#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "Add.h"
#include "Max.h"
#include "Min.h"
#include "Abs.h"
#include "Pow.h"
#include "Divide.h"
#include "Multiply.h"
#include "Substract.h"

using namespace std;

class SyntaxHolder
{
public:
	SyntaxHolder();
	~SyntaxHolder() = default;

	string functionDefinition;
	string variableDefinition;
	map<string, shared_ptr<Function>> functionsMap;
	map<string, int> priority;
	set<std::string> reservedWords;

	bool isReserved(const std::string& word) const;
};