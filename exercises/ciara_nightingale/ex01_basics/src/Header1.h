#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

bool replaceHyphens(std::string &word);

bool isPunc(char& const c);

void cleanWord(std::string &word);

void processWord(std::string &word, std::map<std::string, int> &counter,
		std::string::size_type &maxlen,
		std::string::size_type const minWordLength);

std::vector<std::pair<std::string, int>> const
mapToVector(const std::map<std::string, int> &map);

bool pairValueIsGreater(std::pair<std::string, int> const pair1,
		std::pair<std::string, int> const pair2);

void vectortoFile(std::vector<std::pair<std::string, int>> const counter,
		std::string::size_type const pad);

void uniqueWordCounter(std::string::size_type const minWordLength);

