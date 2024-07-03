#include "Add.h"
#include "Max.h"
#include "Min.h"
#include "Abs.h"
#include "Pow.h"
#include "Divide.h"
#include "Multiply.h"
#include "Substract.h"
#include "SyntaxHolder.h"

SyntaxHolder::SyntaxHolder() 
{
	functionDefinition = "fun";
	variableDefinition = "var";
	functionToClassMap["abs"] = make_unique<Abs>();
	functionToClassMap["min"] = make_unique<Min>();
	functionToClassMap["max"] = make_unique<Max>();
	functionToClassMap["pow"] = make_unique<Pow>();
	functionToClassMap["+"] = make_unique<Add>();
	functionToClassMap["-"] = make_unique<Substract>();
	functionToClassMap["*"] = make_unique<Multiply>();
	functionToClassMap["/"] = make_unique<Divide>();

};