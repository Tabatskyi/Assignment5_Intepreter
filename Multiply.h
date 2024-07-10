#pragma once
#include "Function.h"
class Multiply : public Function
{
public:
	Multiply() {};
	~Multiply() {};
	double Execute(vector<double>) override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
	string GetName() override;
};