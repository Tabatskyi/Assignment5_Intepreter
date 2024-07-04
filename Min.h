#pragma once
#include "Function.h"
class Min : public Function
{
public:
	Min();
	~Min();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

