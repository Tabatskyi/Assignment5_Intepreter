#pragma once
#include "Function.h"
class Pow : public Function
{
public:
	Pow();
	~Pow();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
};

