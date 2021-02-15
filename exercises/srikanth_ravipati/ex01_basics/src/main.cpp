#include <iostream>
#include <fstream>
#include "processLine.h"


int main(int argc, char** argv){

    if (argc < 2){
        throw std::runtime_error("Atleast one argument (filename) should be passed. USAGE: ./a.out inputFileName");
        return 1;
    } else {
        std::cout << "File to be processed: "  << argv[1] << "\n";
    }

    auto nameInFile = argv[1];

    std::vector<char> delimiters = {'\'', '\"', '.', ',', '?', '!', '(', ')', ':', ' ', '-', '}'};
    std::map<std::string, int> mapWordCounter;

    std::ifstream inputFile;
    inputFile.open(nameInFile, std::ios::in);

    std::string line;
    if (inputFile.is_open()){
        while (getline(inputFile, line)){
            processLine(line, delimiters, mapWordCounter);
        }
    }
    inputFile.close();

    std::vector<std::pair<std::string, int>> vecWordCounter;
    for (auto &itr : mapWordCounter){
        vecWordCounter.push_back(itr);
    }

    sort(vecWordCounter.begin(), vecWordCounter.end(), [](auto& a, auto& b){ return a.second > b.second;});

    std::string nameOutFile = "outfile.txt";
    std::ofstream outputFile;
    outputFile.open(nameOutFile, std::ios::out);
    for_each(vecWordCounter.cbegin(), vecWordCounter.cend(), [&outputFile](auto& itr) {outputFile << itr.first << "\t" << itr.second << "\n";});
    outputFile.close();

}
