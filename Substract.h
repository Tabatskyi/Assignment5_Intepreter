#pragma once
#include "Function.h"
class Substract : public Function
{
public:
	Substract();
	~Substract();
	double Execute(int x) override {};
	double Execute(int x, int y) override;
	double Execute(Function* funcsArray) override {};
};

