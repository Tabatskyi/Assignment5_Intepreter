#include "Max.h"

Max::Max() {}
Max::~Max() {}

double Max::Execute(int x, int y) 
{
	if (x >= y)
		return x;
	else
		return y;
}