#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <stack>

#include "SyntaxHolder.h"
#include "CustomFunction.h"
#include "Variable.h"

using namespace std;

static vector<string> splitString(const string& input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}

static string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, (last - first + 1));
}

static bool isNumber(const string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789.-") == string::npos;
}

double evaluateExpression(const string& expr, SyntaxHolder& syntaxHolder)
{
    vector<string> tokens = splitString(expr, ' ');
    stack<double> values;
    stack<shared_ptr<Function>> ops;

    for (auto& token : tokens)
    {
        token = trim(token);
        if (isNumber(token))
        {
            values.push(stod(token));
        }
        else
        {
            while (!ops.empty() && syntaxHolder.priority(ops.top()) >= syntaxHolder.priority(syntaxHolder.functionToClassMap[token]))
            {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                auto op = ops.top(); ops.pop();

                values.push(op->Execute(val1, val2));
            }
            ops.push(syntaxHolder.functionToClassMap[token]);
        }
    }

    while (!ops.empty())
    {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        auto op = ops.top(); ops.pop();

        values.push(op->Execute(val1, val2));
    }

    return values.top();
}

int main()
{
    SyntaxHolder syntaxHolder;
    string inputString;

    while (true)
    {
        cout << "> ";
        getline(cin, inputString);
        if (inputString == "exit")
            break;

        try
        {
            double result = evaluateExpression(inputString, syntaxHolder);
            cout << "< " << result << endl;
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
