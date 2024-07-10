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

static vector<string> tokenize(const string& input)
{
    vector<string> tokens;
    string token;
    for (char ch : input)
    {
        if (isspace(ch))
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else if (isdigit(ch) || ch == '.' || (ch == '-' && token.empty()))
        {
            token += ch;
        }
        else
        {
            if (!token.empty() && isNumber(token))
            {
                tokens.push_back(token);
                token.clear();
            }
            token += ch;
            if (ch == '(' || ch == ')')
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
            }
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }
    return tokens;
}

static double evaluateExpression(const vector<string>& tokens, SyntaxHolder& syntaxHolder)
{
    stack<double> values;
    stack<string> ops;

    for (const string& token : tokens)
    {
        if (isNumber(token))
        {
            values.push(stod(token));
        }
        else if (token == "(")
        {
            ops.push(token);
        }
        else if (token == ")")
        {
            while (!ops.empty() && ops.top() != "(")
            {
                string op = ops.top();
                ops.pop();
                if (syntaxHolder.functionToClassMap.find(op) != syntaxHolder.functionToClassMap.end()) 
                {
                    double result = 0;
                    if (op == "abs") 
                    {
                        double val = values.top(); values.pop();
                        result = syntaxHolder.functionToClassMap[op]->Execute(val);
                    }
                    else 
                    {
                        double val2 = values.top(); 
                        values.pop();
                        double val1 = values.top(); 
                        values.pop();
                        result = syntaxHolder.functionToClassMap[op]->Execute(val1, val2);
                    }
                    values.push(result);
                }
            }
        }
        else if (syntaxHolder.functionToClassMap.find(token) != syntaxHolder.functionToClassMap.end())
        {
            while (!ops.empty() && syntaxHolder.priority(syntaxHolder.functionToClassMap[ops.top()]) >= syntaxHolder.priority(syntaxHolder.functionToClassMap[token]))
            {
                double val2 = values.top(); 
                values.pop();
                double val1 = values.top(); 
                values.pop();
                auto& op = ops.top();
                ops.pop();

                values.push(syntaxHolder.functionToClassMap[op]->Execute(val1, val2));
            }
            ops.push(token);
        }
    }

    while (!ops.empty())
    {
        string op = ops.top();
        ops.pop();
        double val2 = values.top(); 
        values.pop();
        double val1 = values.top(); 
        values.pop();
        values.push(syntaxHolder.functionToClassMap[op]->Execute(val1, val2));
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

        vector<string> tokens = tokenize(inputString);
        try
        {
            double result = evaluateExpression(tokens, syntaxHolder);
            cout << "< " << result << endl;
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}