#pragma once
#include "Function.h"
class Min : public Function
{
public:
	Min();
	~Min();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
};

