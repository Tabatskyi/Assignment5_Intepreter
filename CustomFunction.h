#pragma once
#include "Operator.h"
class CustomFunction : public Function
{
public:
	CustomFunction();
	~CustomFunction();
	double Execute(Function* funcsArray);
private:
};

