#pragma once
#include <string>

using namespace std;

class Function
{
public:
	~Function() = default;
	virtual double Execute() = 0;
	virtual double Execute(double x) = 0;	
	virtual double Execute(double x, double y) = 0;
	virtual string GetName() = 0;
};