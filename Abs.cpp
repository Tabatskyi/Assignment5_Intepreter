#include "Abs.h"

Abs::Abs() {}
Abs::~Abs() {}

double Abs::Execute(double x)
{
	if (x < 0)
		return -x;
	else
		return x;
}



