#pragma once
#include "Function.h"
class Abs : public Function
{
public:
	Abs();
	~Abs();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override;
	double Execute(int x, int y) override { throw "Wrong arguments count"; };
	
};

