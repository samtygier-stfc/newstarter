#include <iostream>
#include "utils.h"
#include "Info_UniqueWords.h"

void processLine(const std::string& lineInput, const std::string& delimiters, infoUniqueWords& uniqueWords){
    bool isDelimiter;
    std::string word;

    for (int i=0; i <= lineInput.size(); i++){

        isDelimiter = isInputCharDelimiter(lineInput[i], delimiters);

        if (isDelimiter){

           if (word.size() > 4){
              uniqueWords.accountForElement(word);
           }
           word = "";

        } else {
           appendLowerCaseChar(word, lineInput[i]);
        }
    }
}