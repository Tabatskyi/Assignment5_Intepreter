#pragma once
#include "Function.h"
class Substract : public Function
{
public:
	Substract();
	~Substract();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
};

