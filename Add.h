#pragma once
#include "Function.h"
class Add : public Function
{
public:
	Add();
	~Add();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

