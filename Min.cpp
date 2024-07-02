#include "Min.h"

Min::Min() {}
Min::~Min() {}

double Min::Execute(int x, int y)
{
	if (x <= y)
		return x;
	else
		return y;
}