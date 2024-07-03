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
    
    
    for (const string& word : words)
    {
        cout << word << endl;
    }
    
    return 0;
}