#pragma once
#include "Function.h"
class Divide : public Function
{
public:
	Divide();
	~Divide();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

