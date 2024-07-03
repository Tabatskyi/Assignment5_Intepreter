#pragma once
#include "Function.h"
class CustomFunction : public Function
{
public:
	CustomFunction(char* name);
	~CustomFunction() = default;
	double Execute(int x) override {};
	double Execute(int x, int y) override {};
	double Execute(Function* funcsArray) override;
	char* GetName();
	void SetName(char* name);
private:
	char* name;
};

