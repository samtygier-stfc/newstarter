#include "processLine.h"

void accountForWord(std::map<std::string,int>& inputMap, const std::string& inputWord){
    auto it = inputMap.find(inputWord);
    if (it != inputMap.end()){
       it->second++;
    } else {
    inputMap.insert(std::pair<std::string,int>(inputWord,1));
    }
}

void processLine(const std::string& lineInput, const std::vector<char>& delimiters, std::map<std::string,int>& inputMap){
    bool isDelimiter;
    std::string word;
    char tmpChar;
    auto lineSize = static_cast<int>(lineInput.size());

    for (auto i=0; i <= lineSize; i++){

        tmpChar = lineInput[i];
        isDelimiter = std::any_of(delimiters.begin(), delimiters.end(), [tmpChar](auto &c){return (c == tmpChar);});

        // Second condition to account for a word at the end of line 
        // that does not have any of the specified delimiter.
        if (isDelimiter | (i == lineSize)){
//           std::cout << "word: " << word << "\n";
           if (word.size() > 4){
              accountForWord(inputMap, word);
           }
           word = "";

        } else {
           word += static_cast<char>(std::tolower(tmpChar));
        }
    }
}