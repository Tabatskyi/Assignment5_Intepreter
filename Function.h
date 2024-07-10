#pragma once
#include <string>
#include <vector>

using namespace std;

class Function
{
public:
	~Function() = default;
	virtual double Execute(vector<double>) = 0;
	virtual double Execute(double x) = 0;	
	virtual double Execute(double x, double y) = 0;
	virtual string GetName() = 0;
};