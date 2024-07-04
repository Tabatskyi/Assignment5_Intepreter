#pragma once
#include "Function.h"
class Max : public Function
{
public:
	Max();
	~Max();
	double Execute() override { throw "Wrong arguments count"; };
	double Execute(int x) override { throw "Wrong arguments count"; };
	double Execute(int x, int y) override;
};

