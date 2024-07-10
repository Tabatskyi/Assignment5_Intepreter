#include "Min.h"

double Min::Execute(double x, double y)
{
	if (x <= y)
		return x;
	else
		return y;
}

string Min::GetName()
{
	return "min";
}