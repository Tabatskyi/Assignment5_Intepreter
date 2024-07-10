#include "Max.h"

double Max::Execute(double x, double y)
{
	if (x >= y)
		return x;
	else
		return y;
}

string Max::GetName()
{
	return "max";
}