#include <iostream>
#include <cctype>

void appendLowerCaseChar(std::string& word, char c){
    int iChar = std::tolower(c);
    word += static_cast<char>(iChar);
}

bool isInputCharDelimiter(char input, const std::string& delimiters){
    bool result = false;

    for (int i=0; i < delimiters.size(); ++i){
        if (input == delimiters[i]){
           result = true;
           break;
        }
    }
    return result;
}