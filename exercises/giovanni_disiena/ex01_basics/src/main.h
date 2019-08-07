#ifndef MAIN_H
#define MAIN_H

#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <string>

// declare map/lamba/pair/set types which will store values
// in non-increasing order unsing comparison logic
typedef std::map<std::string, int> StrIntMap;
typedef std::pair<std::string, int> StrIntPair;
typedef const std::function<bool(StrIntPair, StrIntPair)> &Comparator;

std::string str_tolower(std::string &word);
void cleanWord(std::string &word, std::vector<std::string> &cleaned_words);
void orderWords(const StrIntMap &cleanedMap,
								std::vector<StrIntPair> &outputVector, const Comparator &cmp);
const std::string formatWhitespace(const std::string &str_1,
																	 const std::size_t &max_len);
bool readFile(const std::string &filename, StrIntMap &inputmap,
							std::size_t &max_len, const std::size_t char_min = 4);
const void writeFile(const std::vector<StrIntPair> &orderedPair,
										 const std::size_t &, bool &readBool);

#endif // MAIN_H