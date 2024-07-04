#pragma once
#include "Function.h"
#include "Variable.h"
#include <vector>

using namespace std;
class CustomFunction : public Function
{
public:
	CustomFunction(char* name);
	~CustomFunction() = default;

	double Execute() override;
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override { throw "Wrong arguments count"; };

	char* GetName();
	void SetName(char* name);

	void AddArgument(Variable* arg);
	void AddFunction(Function* func);
private:
	char* name;
	vector<Function*> functions;
	vector<Variable*> arguments;
};

