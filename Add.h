#pragma once
#include "Function.h"
class Add : public Function
{
public:
	Add();
	~Add();
	double Execute(int x, int y);
};

