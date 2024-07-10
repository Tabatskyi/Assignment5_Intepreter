#include "Pow.h"

double Pow::Execute(double x, double y)
{
	double result = x;
	for (int i = 0; i < y - 1; i++)
	{
		result *= x;
	}
	return result;
}

string Pow::GetName()
{
	return "pow";
}