#pragma once
#include "Function.h"
class Abs : public Function
{
public:
	Abs() {};
	~Abs() {};
	double Execute(vector<double>) override { throw "Wrong arguments count"; };
	double Execute(double x) override;
	double Execute(double x, double y) override { throw "Wrong arguments count"; };
	string GetName() override;
};