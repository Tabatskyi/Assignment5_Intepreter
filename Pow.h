#pragma once
#include "Function.h"
class Pow : public Function
{
public:
	Pow();
	~Pow();
	double Execute(int x) override {};
	double Execute(int x, int y) override;
	double Execute(Function* funcsArray) override {};
};

