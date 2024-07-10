#pragma once
#include "Function.h"
class Add : public Function
{
public:
	Add() {};
	~Add() {};
	double Execute(vector<double>) override { throw "Wrong arguments count"; };
	double Execute(double x) override { throw "Wrong arguments count"; };
	double Execute(double x, double y) override;
	string GetName() override;
};