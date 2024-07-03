#pragma once
#include <iostream>
#include <vector>
#include <map>

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
	map<string, unique_ptr<Function>> functionToClassMap;
};

