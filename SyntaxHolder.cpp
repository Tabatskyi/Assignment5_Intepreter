#include "SyntaxHolder.h"

SyntaxHolder::SyntaxHolder() 
{
	functionDefinition = "fun";
	variableDefinition = "var";

	functionToClassMap["abs"] = make_shared<Abs>();
	functionToClassMap["min"] = make_shared<Min>();
	functionToClassMap["max"] = make_shared<Max>();
	functionToClassMap["pow"] = make_shared<Pow>();

	functionToClassMap["+"] = make_shared<Add>();
	functionToClassMap["-"] = make_shared<Substract>();
	functionToClassMap["*"] = make_shared<Multiply>();
	functionToClassMap["/"] = make_shared<Divide>();
};