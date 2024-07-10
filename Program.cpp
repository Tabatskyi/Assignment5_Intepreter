#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <stack>
#include <map>
#include <cctype>

#include "SyntaxHolder.h"
#include "CustomFunction.h"
#include "Variable.h"

using namespace std;

map<string, double> variables;

static bool isNumber(const string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789.-") == string::npos;
}

static bool isVariableName(const string& str, const SyntaxHolder& syntaxHolder)
{
    if (syntaxHolder.isReserved(str))
        return false;

    for (char c : str)
        if (!isalpha(c) && c != '_')
            return false;
    return true;
}

static vector<string> tokenize(const string& input)
{
    vector<string> tokens;
    string token;
    bool isFunctionName = false;

    for (size_t i = 0; i < input.length(); ++i)
    {
        char ch = input[i];
        if (isspace(ch))
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
            isFunctionName = false;
        }
        else if (isdigit(ch) || ch == '.' || (ch == '-' && token.empty()))
            token += ch;

        else if (isalpha(ch) || ch == '_')
        {
            token += ch;
            isFunctionName = true;
        }
        else if (ch == '(' || ch == ')' || ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, ch));
            isFunctionName = false;
        }
    }
    if (!token.empty())
        tokens.push_back(token);

    return tokens;
}

static double evaluateExpression(const vector<string>& tokens, SyntaxHolder& syntaxHolder, bool& suppressOutput)
{
    stack<double> values;
    stack<string> ops;

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        const string& token = tokens[i];

        if (token == "var" && i + 2 < tokens.size() && tokens[i + 2] == "=")
        {
            string varName = tokens[i + 1];
            if (!isVariableName(varName, syntaxHolder))
                throw runtime_error("Invalid variable name: " + varName);

            i += 2; // Skip 'var' and '='
            double value = evaluateExpression(vector<string>(tokens.begin() + i + 1, tokens.end()), syntaxHolder, suppressOutput);
            variables[varName] = value;
            suppressOutput = true;
            return value;
        }
        else if (isVariableName(token, syntaxHolder) && i + 1 < tokens.size() && tokens[i + 1] == "=")
        {
            string varName = token;
            if (!isVariableName(varName, syntaxHolder))
                throw runtime_error("Invalid variable name: " + varName);

            i += 1; // Skip '='
            double value = evaluateExpression(vector<string>(tokens.begin() + i + 1, tokens.end()), syntaxHolder, suppressOutput);
            variables[varName] = value;
            suppressOutput = true;
            return value;
        }
        else if (isNumber(token))
        {
            values.push(stod(token));
        }
        else if (isVariableName(token, syntaxHolder))
        {
            if (variables.find(token) == variables.end())
                throw runtime_error("Variable not defined: " + token);

            values.push(variables[token]);
        }
        else if (token == "=")
            continue;

        else if (token == "(")
        {
            ops.push(token);
        }
        else if (token == ")")
        {
            while (!ops.empty() && ops.top() != "(")
            {
                auto op = ops.top();
                ops.pop();
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                values.push(syntaxHolder.functionsMap[op]->Execute(val1, val2));
            }
            ops.pop();
        }
        else if (syntaxHolder.functionsMap.find(token) != syntaxHolder.functionsMap.end())
        {
            while (!ops.empty() && syntaxHolder.priority[ops.top()] >= syntaxHolder.priority[token])
            {
                auto op = ops.top();
                ops.pop();
                if (op == "abs")
                {
                    double val = values.top();
                    values.pop();
                    values.push(syntaxHolder.functionsMap[op]->Execute(val));
                    continue;
                }
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                values.push(syntaxHolder.functionsMap[op]->Execute(val1, val2));
            }
            ops.push(token);
        }
        else
        {
            ops.push(token);
        }
    }

    while (!ops.empty())
    {
        auto op = ops.top();
        ops.pop();
        if (op == "abs")
        {
            double val = values.top();
            values.pop();
            values.push(syntaxHolder.functionsMap[op]->Execute(val));
            continue;
        }
        else if (op == "=")
        {
            double val = values.top();
            values.pop();
            string varName = ops.top();
            ops.pop();
            variables[varName] = val;
            values.push(val);
        }
        else
        {
            double val2 = values.top();
            values.pop();
            double val1 = values.top();
            values.pop();
            values.push(syntaxHolder.functionsMap[op]->Execute(val1, val2));
        }
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
        bool suppressOutput = false;
        try
        {
            double result = evaluateExpression(tokens, syntaxHolder, suppressOutput);
            if (!suppressOutput)
                cout << "< " << result << endl;
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}