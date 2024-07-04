#include "CustomFunction.h"

CustomFunction::CustomFunction(const char* name)
{
	this->name = name;
}

CustomFunction::~CustomFunction()
{
	for (Function* function : functions)
	{
		delete function;
	}

	for (Variable* argument : arguments)
	{
		delete argument;
	}
}

const char* CustomFunction::GetName()
{
	return name;
}


double CustomFunction::Execute()
{
	double result = 0;

	for (Function* function : functions)
	{
		Variable* arg1 = get<0>(functionArguments[function]);
		Variable* arg2 = get<1>(functionArguments[function]);
		result += function->Execute(arg1->getValue(), arg2->getValue());
	}

	return result;
}

void CustomFunction::AddArgument(Variable* arg)
{
	arguments.push_back(arg);
}

void CustomFunction::AddFunction(Function* func)
{
	functions.push_back(func);
}

void CustomFunction::AddFunctionArgument(Function* func, tuple<Variable*, Variable*> args)
{
	functionArguments[func] = args;
	AddArgument(get<0>(args));
	AddArgument(get<1>(args));
	AddFunction(func);
}