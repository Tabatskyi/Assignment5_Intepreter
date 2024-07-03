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

double CustomFunction::Execute(Function* funcsArray)
{
	return 0;
}

