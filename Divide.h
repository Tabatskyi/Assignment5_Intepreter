#pragma once
#include "Function.h"
class Divide : public Function
{
public:
	Divide();
	~Divide();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
};

