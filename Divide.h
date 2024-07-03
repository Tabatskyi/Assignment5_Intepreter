#pragma once
#include "Function.h"
class Divide : public Function
{
public:
	Divide();
	~Divide();
	double Execute(int x) override {};
	double Execute(int x, int y) override;
	double Execute(Function* funcsArray) override {};
};

