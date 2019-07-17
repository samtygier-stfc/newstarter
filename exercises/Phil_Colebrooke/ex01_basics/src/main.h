#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/// Populates a map with every unique word in a text file and the number of
/// occurrences
bool countWords(const std::string &filename,
                std::map<std::string, int> &wordCounter,
                const int &minWordLength);

/// Removes punctuation from a word and converts it to lowercase
std::string cleanUpWord(std::string &word);

/// Sorts the word-usage pairs in descending order of number of occurrences
std::vector<std::pair<int, std::string>>
orderByUsage(std::map<std::string, int> &wordCounter);

/// Writes all of the word-usage pairs to a file
void writeToFile(std::vector<std::pair<int, std::string>> &wordsAndCounts,
                 const std::string &outputFilename);

#endif // EXERCISE1_H
