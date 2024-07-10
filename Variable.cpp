#include "Variable.h"

Variable::Variable(string name, double val)
{
	this->name = name;
	value = val;
}
Variable::~Variable()
{
}
string Variable::getName()
{
	return name;
}
double Variable::getValue() const
{
	return value;
}
void Variable::setValue(double val)
{
	value = val;
}