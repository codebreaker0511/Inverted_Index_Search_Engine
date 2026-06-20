#include "../include/Tokenizer.h"

#include <cctype>
#include <string>
#include <vector>

using namespace std;

vector<string> Tokenizer::tokenize(const string& text)
{
    vector<string> tokens;
    string currentWord;

    for(char ch : text)
    {
        if(isalnum(ch))
        {
            currentWord += tolower(ch);
        }
        else
        {
            if(!currentWord.empty())
            {
                tokens.push_back(currentWord);
                currentWord.clear();
            }
        }
    }

    if(!currentWord.empty())
    {
        tokens.push_back(currentWord);
    }

    return tokens;
}