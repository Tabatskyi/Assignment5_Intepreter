#include "Pow.h"

Pow::Pow() {}
Pow::~Pow() {}

double Pow::Execute(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		x *= x;
	}
	return x;
}