#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

void accountForWord(std::map<std::string, int> &, const std::string &);
void processLine(const std::string &, const std::vector<char> &,
                 std::map<std::string, int> &);