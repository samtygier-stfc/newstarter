/**
 * Skeleton main routine
 */

#include <iostream>
#include <string>
#include <fstream>
#include "processLine.h"

int main(int argc, char** argv)
{
    if (argc < 2){
       std::cout << "Atleast one argument (filename) should be passed." << "\n";
       return 1;
    } else {
    std::cout << "File to be processed: "  << argv[1] << "\n";
    }

    auto nameInFile = argv[1];

    std::string delimiters = "'\".,?!(): -}";
    std::string line;

    infoUniqueWords uniqueWords;

    std::ifstream inputFile;
    inputFile.open(nameInFile, std::ios::in);

    if (inputFile.is_open()){
        while (getline(inputFile, line)){
//              std::cout << "line: " << "\t" << line << "\n";
              processLine(line, delimiters, uniqueWords);
        }
    }

    inputFile.close();

    std::string nameOutFile = "outfile.txt";
    std::ofstream outputFile;

    outputFile.open(nameOutFile, std::ios::out);
    if (outputFile.is_open()){
       outputFile << "Word" << "\t" << "Usage" << "\n";
       for (int i=0; i < uniqueWords.getSize(); i++){
           outputFile << uniqueWords.getElementValue(i) << "\t" << uniqueWords.getElementCount(i) << "\n";
       }
    }
    outputFile.close();

    return 0;
}
