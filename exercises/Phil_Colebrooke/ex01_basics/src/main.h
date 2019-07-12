#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

void countWords(std::string filename, std::map<std::string, int>& wordCounter);

std::string cleanUpWord(std::string word);

std::vector<std::pair<int, std::string>>
orderByUsage(std::map<std::string, int>& wordCounter);

void writeToFile(std::vector<std::pair<int, std::string>> wordCounter);

#endif EXERCISE1_H