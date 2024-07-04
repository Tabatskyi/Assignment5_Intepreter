#pragma once
#include "Function.h"
#include "Variable.h"
#include <vector>
#include <map>

using namespace std;
class CustomFunction : public Function
{
public:
	CustomFunction(const char* name);
	~CustomFunction();

	double Execute() override;
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override { throw "Wrong arguments count"; };

	const char* GetName();

	void AddArgument(Variable* arg);
	void AddFunction(Function* func);
	void AddFunctionArgument(Function* func, tuple<Variable*, Variable*> arg);
private:
	const char* name;
	vector<Function*> functions;
	vector<Variable*> arguments;
	map<Function*, tuple<Variable*, Variable*>> functionArguments;
};

