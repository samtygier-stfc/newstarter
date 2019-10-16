// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using WordCount = std::pair<std::string, int>;
using WordCounts = std::map<std::string, int>;

namespace {
  constexpr auto FOLDER_NAME = "D:\\newstarter\\builds\\WordCountDataFiles\\";
  constexpr auto CHARS_TO_REMOVE = ".,?'\"!():";
}

/**
 * Returns the sort order of the Word Counts - sort descending
 * @param x First word count
 * @param y Second word count
 * @return boolean which is true if the first word count is bigger than the second
 */
bool compare(const WordCount& x, const WordCount& y) {
  return x.second > y.second;
}

int main(int argc, char ** argv)
{
  std::string fileName;
  if (argc == 2) {
    fileName = argv[1];

    std::ifstream inFile(FOLDER_NAME + fileName);
    
    if (inFile) {
      std::string word_withhyphens;
      WordCounts counters;

      // read file in one word at a time
      while (inFile >> word_withhyphens) {
        std::istringstream ss(word_withhyphens);
        // split any words containing hyphens into two
        std::string word;
        while (std::getline(ss, word, '-')) {
          for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
          }
          for (int i = 0; i < strlen(CHARS_TO_REMOVE); i++) {
            word.erase(std::remove(word.begin(), word.end(), CHARS_TO_REMOVE[i]), word.end());
          }
          if (word.length() > 4) {
            counters[word]++;
          }
        }
      }

      std::vector<WordCount> countersVec;

      //sort(counters.begin(),counters.end(),Compare); // not possible on a map because doesn't have random access

      // copy to vector of pairs so can sort. Could have copied to another map (multimap) instead
      std::copy(counters.begin(), counters.end(), std::back_inserter<std::vector<WordCount>>(countersVec));
      sort(countersVec.begin(), countersVec.end(), compare);

      std::ofstream outFile(std::string(FOLDER_NAME) + "results.txt");
      if (outFile) {
        outFile << "Word" << "\t" << "Usage" << std::endl;

        for (const auto& WordAndCount : countersVec) {
          outFile << WordAndCount.first << "\t" << WordAndCount.second << std::endl;
        }

      }
      else {
        std::cout << "Cannot open specified output file" << std::endl;
      }
      inFile.close();
      outFile.close();

      std::cout << "Word counting succeeded!" << std::endl;
    }
    else {
      std::cout << "Cannot open specified input file" << std::endl;
      return 1;
    }
  }
  else if (argc == 1) {
    std::cout << "No filename supplied" << std::endl;
    return 1;
  }
  else {
    std::cout << "Unexpected number of arguments supplied" << std::endl;
    return 1;
  }
}