#include "SyntaxHolder.h"

SyntaxHolder::SyntaxHolder() 
{
	functionDefinition = "fun";
	variableDefinition = "var";

	functionsMap["abs"] = make_shared<Abs>();
	functionsMap["min"] = make_shared<Min>();
	functionsMap["max"] = make_shared<Max>();
	functionsMap["pow"] = make_shared<Pow>();

	functionsMap["+"] = make_shared<Add>();
	functionsMap["-"] = make_shared<Substract>();
	functionsMap["*"] = make_shared<Multiply>();
	functionsMap["/"] = make_shared<Divide>();

	priority["abs"] = 4;
	priority["min"] = 3;
	priority["max"] = 3;
	priority["pow"] = 4;

	priority["+"] = 1;
	priority["-"] = 1;
	priority["*"] = 2;
	priority["/"] = 2;

	reservedWords.insert({ "abs", "min", "max", "pow", "+", "-", "*", "/", "(", ")", functionDefinition, variableDefinition });
};

bool SyntaxHolder::isReserved(const std::string& word) const
{
	return reservedWords.find(word) != reservedWords.end();
}