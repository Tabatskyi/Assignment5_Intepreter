#include "Abs.h"

double Abs::Execute(double x)
{
	if (x < 0)
		return -x;
	return x;
}

string Abs::GetName()
{
	return "abs";
}