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

bool compare(const std::pair<std::string,int>& x, const std::pair<std::string,int>& y) {
  return x.second > y.second;
}

int main(int argc, char ** argv)
{
  std::string fileName;
  if (argc == 2) {
    fileName = argv[1];

    std::string folderName ="D:\\newstarter\\builds\\WordCountDataFiles\\";
    std::ifstream inFile(folderName + fileName);
    
    if (inFile) {
      std::string s_withhyphens,s;
      std::map<std::string, int> counters;

      // read file in one word at a time
      while (inFile >> s_withhyphens) {
        std::istringstream ss(s_withhyphens);
        // split any words containing hyphens into two
        while (std::getline(ss, s, '-')) {
          for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
          }
          char charsToRemove[] = ".,?'\"!():";
          for (int i = 0; i < strlen(charsToRemove); i++) {
            s.erase(std::remove(s.begin(), s.end(), charsToRemove[i]), s.end());
          }
          if (s.length() > 4) {
            counters[s]++;
          }
        }
      }

      std::vector<std::pair<std::string, int>> vec;

      //sort(counters.begin(),counters.end(),Compare); // not possible on a map because doesn't have random access

      // copy to vector of pairs so can sort. Could have copied to another map (multimap) instead
      std::copy(counters.begin(), counters.end(), std::back_inserter<std::vector<std::pair<std::string, int>>>(vec));
      sort(vec.begin(), vec.end(), compare);

      std::ofstream outFile(folderName + "results.txt");
      if (outFile) {
        outFile << "Word" << "\t" << "Usage" << std::endl;
        for (std::vector<std::pair<std::string, int>>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
          outFile << it->first << "\t" << it->second << std::endl;
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