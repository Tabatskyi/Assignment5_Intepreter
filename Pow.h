#pragma once
#include "Function.h"
class Pow : public Function
{
public:
	Pow();
	~Pow();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

