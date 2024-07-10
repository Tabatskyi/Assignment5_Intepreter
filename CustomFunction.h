#pragma once
#include "Function.h"
#include "Variable.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;
class CustomFunction : public Function
{
public:
	CustomFunction(string name);
	~CustomFunction();

	double Execute() override;
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override { throw "Wrong arguments count"; };

	string GetName();

	void AddArgument(Variable* arg);
	void AddFunction(shared_ptr<Function> func);
	void AddFunctionArgument(shared_ptr<Function> func, tuple<Variable*, Variable*> arg);
private:
	string name;
	vector<shared_ptr<Function>> functions;
	vector<Variable*> arguments;
	map<shared_ptr<Function>, tuple<Variable*, Variable*>> functionArguments;
};

