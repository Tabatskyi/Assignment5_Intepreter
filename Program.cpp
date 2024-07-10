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

static bool isNumber(const string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789.-") == string::npos;
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
        {
            if (isFunctionName) 
            {
                tokens.push_back(token);
                token.clear();
                isFunctionName = false;
            }
            token += ch;
        }
        else if (isalpha(ch)) 
        {
            if (!isFunctionName && !token.empty()) 
            {
                tokens.push_back(token);
                token.clear();
            }
            token += ch;
            isFunctionName = true;
        }
        else if (ch == '(') 
        {
            if (isFunctionName) 
            {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, ch));
            isFunctionName = false;
        }
        else if (ch == ')') 
        {
            if (!token.empty()) 
            {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, ch));
        }
        else 
        {
            if (!token.empty()) 
            {
                tokens.push_back(token);
                token.clear();
            }
            token += ch;
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
        double val2 = values.top();
        values.pop();
        double val1 = values.top();
        values.pop();

        values.push(syntaxHolder.functionsMap[op]->Execute(val1, val2));
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