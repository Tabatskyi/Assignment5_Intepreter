#include "Min.h"

Min::Min() {}
Min::~Min() {}

double Min::Execute(double x, double y)
{
	if (x <= y)
		return x;
	else
		return y;
}