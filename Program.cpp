#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "SyntaxHolder.h"
#include "CustomFunction.h"

using namespace std;


static vector<string> splitString(const string& inputString)
{
    SyntaxHolder syntaxHolder;
    vector<string> result;
    istringstream iss(inputString);
    string word;
    
    while (iss >> word)
    {
        result.push_back(word);
    }
    
    return result;
}

int main()
{
    string inputString;
    getline(std::cin, inputString);
    
    vector<string> words = splitString(inputString);
    
    CustomFunction customFunction("test");

    customFunction.AddFunctionArgument(new Add(), make_tuple(new Variable("x", 6), new Variable("y", 10)));
    
    for (const string& word : words)
    {
        cout << word << endl;
    }
    
    cout << customFunction.Execute() << endl;

    return 0;
}