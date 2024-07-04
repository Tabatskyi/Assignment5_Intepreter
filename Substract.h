#pragma once
#include "Function.h"
class Substract : public Function
{
public:
	Substract();
	~Substract();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

