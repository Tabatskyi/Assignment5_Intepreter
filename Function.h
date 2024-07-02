#pragma once
class Function
{
public:
	~Function() = default;
	virtual double Execute(int x) = 0;	
	virtual double Execute(int x, int y) = 0;
	virtual double Execute(Function* funcsArray) = 0;
};

