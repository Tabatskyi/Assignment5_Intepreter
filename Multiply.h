#pragma once
#include "Function.h"
class Multiply : public Function
{
public:
	Multiply();
	~Multiply();
	double Execute(int x, int y);
};

