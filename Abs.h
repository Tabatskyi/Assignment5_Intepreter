#pragma once
#include "Function.h"
class Abs : public Function
{
public:
	Abs();
	~Abs();
	double Execute(int x, int y);
};

