#pragma once
#include "Function.h"
#include "Variable.h"
#include <vector>
#include <map>
#include <memory>
#include <string>

using namespace std;

class CustomFunction : public Function
{
public:
    CustomFunction(string name);
    ~CustomFunction();

    double Execute(vector<double> args) override;
    double Execute(double x) override { throw "Wrong arguments count"; }
    double Execute(double x, double y) override { throw "Wrong arguments count"; }

    string GetName();

    void AddArgument(Variable* arg);
    void AddFunction(shared_ptr<Function> func);
    void AddFunctionArgument(shared_ptr<Function> func, tuple<Variable*, Variable*> arg);
    void SetBody(vector<string> body);
    void SetArguments(vector<string> args);

private:
    static int CheckArguments(vector<Variable*> arguments, Variable* target);
    string name;
    vector<shared_ptr<Function>> functions;
    vector<Variable*> arguments;
    map<shared_ptr<Function>, tuple<Variable*, Variable*>> functionArguments;
    vector<string> body;
    vector<string> argumentNames;
};