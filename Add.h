#pragma once
#include "Function.h"
class Add : public Function
{
public:
	Add();
	~Add();
	double Execute(int x) override {};
	double Execute(int x, int y) override;
	double Execute(Function* funcsArray) override {};
};

