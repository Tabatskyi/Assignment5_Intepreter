#include "Pow.h"

double Pow::Execute(double x, double y)
{
	for (int i = 0; i < y; i++)
	{
		x *= x;
	}
	return x;
}

string Pow::GetName()
{
	return "pow";
}