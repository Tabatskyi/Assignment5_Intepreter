#include "Abs.h"

Abs::Abs() {}
Abs::~Abs() {}

double Abs::Execute(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}



