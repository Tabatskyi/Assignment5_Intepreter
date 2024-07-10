#include <string>
#include <vector>
#include <sstream>
#include <functional>

#include "SyntaxHolder.h"
#include "CustomFunction.h"

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
    return str.substr(first, (last - first + 1));
}

int main()
{
    SyntaxHolder syntaxHolder;
    string inputString;
    cout << ": ";
    getline(cin, inputString);

    vector<string> parts = splitString(inputString, ':');
    if (parts.size() != 2) 
    {
        cerr << "Invalid function format.";
        return 1;
    }

    string signature = trim(parts[0]);
    string expression = trim(parts[1]);

    parts = splitString(signature, '(');
    string functionName = trim(parts[0]);
    string params = trim(parts[1]);
    params.pop_back();

    vector<string> parameters = splitString(params, ',');
    vector<Variable*> args;

    int dummyValue = 1;
    for (const string& param : parameters) 
    {
        args.push_back(new Variable(trim(param), dummyValue++));
    }

    CustomFunction customFunction(functionName);

    customFunction.AddFunctionArgument(syntaxHolder.functionToClassMap["min"], { args[0], args[1] });
    customFunction.AddFunctionArgument(syntaxHolder.functionToClassMap["+"], { args[1], new Variable("", customFunction.Execute()) });

    cout << customFunction.Execute() << endl;

    return 0;
}
