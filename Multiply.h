#pragma once
#include "Function.h"
class Multiply : public Function
{
public:
	Multiply();
	~Multiply();
	double Execute(int x) override {};
	double Execute(int x, int y) override;
	double Execute(Function* funcsArray) override {};
};

