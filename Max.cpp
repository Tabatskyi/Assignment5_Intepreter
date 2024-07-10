#include "Max.h"

Max::Max() {}
Max::~Max() {}

double Max::Execute(double x, double y)
{
	if (x >= y)
		return x;
	else
		return y;
}