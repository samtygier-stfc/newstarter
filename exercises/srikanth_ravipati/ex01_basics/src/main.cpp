/**
 * Skeleton main routine
 */

#include <iostream>
#include <string>
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
    uniqueWords.printToFile(outputFile);
    outputFile.close();

    return 0;
}
