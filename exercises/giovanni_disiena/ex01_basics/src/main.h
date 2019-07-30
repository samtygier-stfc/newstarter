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
typedef std::map<std::string, int> MapType;
typedef std::pair<std::string, int> pair;
typedef std::function<bool(pair, pair)> Comparator;

std::string str_tolower(std::string&);
void cleanWord(std::string&, std::vector<std::string>&);
void orderWords(const MapType&, std::vector<pair>&, Comparator&);
void readFile(const std::string&, MapType&, const std::size_t = 4);
void writeFile(const std::vector<pair>&);

#endif // MAIN_H