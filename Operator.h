#pragma once
#include "Function.h"
class Operator : public Function
{
public:
	Operator();
	~Operator();
	double Execute(double x, double y);
private:
};

