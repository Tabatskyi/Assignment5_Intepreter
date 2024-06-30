#pragma once
#include "Function.h"
class CustomFunction : public Function
{
public:
	CustomFunction(char* name);
	~CustomFunction();
	double Execute(Function* funcsArray);
private:
	char* name;
};

