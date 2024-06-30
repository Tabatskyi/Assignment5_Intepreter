#pragma once
#include "Function.h"
class Pow : public Function
{
public:
	Pow();
	~Pow();
	double Execute(int x, int y);
};

