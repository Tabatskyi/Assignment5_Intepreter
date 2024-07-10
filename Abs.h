#pragma once
#include "Function.h"
class Abs : public Function
{
public:
	Abs();
	~Abs();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override;
	double Execute(double x, double y) override { throw "Wrong arguments count"; };
	
};

