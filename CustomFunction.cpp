#include "CustomFunction.h"

CustomFunction::CustomFunction(string name)
{
	this->name = name;
}

CustomFunction::~CustomFunction()
{
	for (Variable* argument : arguments)
	{
		delete argument;
	}
}

string CustomFunction::GetName()
{
	return name;
}


double CustomFunction::Execute()
{
	double result = 0;

	for (shared_ptr<Function> function : functions)
	{
		Variable* arg1 = get<0>(functionArguments[function]);
		Variable* arg2 = get<1>(functionArguments[function]);
		result += function->Execute(arg1->getValue(), arg2->getValue());
	}

	return result;
}

int CustomFunction::CheckArguments(vector<Variable*> arguments, Variable* target)
{
	if (find(arguments.begin(), arguments.end(), target) != arguments.end())
	{
		return distance(arguments.begin(), find(arguments.begin(), arguments.end(), target));
	}
	return -1;
}

void CustomFunction::AddArgument(Variable* arg)
{
	int index = CheckArguments(arguments, arg);
	if (index >= 0)
	{
		arguments[index] = arg;
	}
	else
	{
		arguments.push_back(arg);
	}
}

void CustomFunction::AddFunction(shared_ptr<Function> func)
{
	functions.push_back(func);
}

void CustomFunction::AddFunctionArgument(shared_ptr<Function> func, tuple<Variable*, Variable*> args)
{
	functionArguments[func] = args;
	AddArgument(get<0>(args));
	AddArgument(get<1>(args));
	AddFunction(func);
}