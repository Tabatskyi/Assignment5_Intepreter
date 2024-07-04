#pragma once
#include "Function.h"
class Multiply : public Function
{
public:
	Multiply();
	~Multiply();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

