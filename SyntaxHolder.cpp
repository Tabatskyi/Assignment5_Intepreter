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

int SyntaxHolder::priority(const shared_ptr<Function>& func)
{
	if (dynamic_pointer_cast<Add>(func) || dynamic_pointer_cast<Substract>(func))
		return 1;  
	else if (dynamic_pointer_cast<Multiply>(func) || dynamic_pointer_cast<Divide>(func))
		return 2; 
	else if (dynamic_pointer_cast<Pow>(func))
		return 3; 

	return 0; 
}