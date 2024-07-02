#pragma once
#include "Function.h"
class CustomFunction : public Function
{
public:
	CustomFunction(char* name);
	~CustomFunction();
	double Execute(Function* funcsArray);
	char* GetName();
	void SetName(char* name);
private:
	char* name;
};

