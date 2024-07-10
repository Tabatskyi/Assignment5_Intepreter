#pragma once
#include "Function.h"
class Max : public Function
{
public:
	Max() {};
	~Max() {};
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
	string GetName() override;
};