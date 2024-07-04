#include "CustomFunction.h"

CustomFunction::CustomFunction(char* name)
{
	this->name = name;
}

char* CustomFunction::GetName()
{
	return name;
}

void CustomFunction::SetName(char* name)
{
	this->name = name;
}

double CustomFunction::Execute()
{
	return 0;
}

void CustomFunction::AddArgument(Variable* arg)
{
	arguments.push_back(arg);
}

void CustomFunction::AddFunction(Function* func)
{
	functions.push_back(func);
}