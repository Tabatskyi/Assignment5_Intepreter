#pragma once
#include <string>

using namespace std;

class Variable
{
public:
	Variable(string name, double val);
	~Variable();

	string getName();
	double getValue() const;

	void setValue(double val);
private:
	string name;
	double value;
};