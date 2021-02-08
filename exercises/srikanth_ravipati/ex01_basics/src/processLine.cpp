#include <iostream>
#include "utils.h"
#include "infoUniqueWords.h"

void processLine(const std::string& lineInput, const std::string& delimiters, infoUniqueWords& uniqueWords){
    bool isDelimiter;
    std::string word;

    for (int i=0; i <= lineInput.size(); i++){

        isDelimiter = isInputCharDelimiter(lineInput[i], delimiters);

        // Second condition accounts for a word at the end of line
        // that does end with any of the specified delimiter.
        if (isDelimiter | (i == lineInput.size())){

           if (word.size() > 4){
              uniqueWords.accountForElement(word);
           }
           word = "";

        } else {
           appendLowerCaseChar(word, lineInput[i]);
        }
    }
}