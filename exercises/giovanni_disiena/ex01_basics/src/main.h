#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

// define map type which stores values in descending order
typedef std::map<std::string, int, std::greater <int> > maptype;

void cleanWords(std::string&);
void readFile(const std::string&, maptype&, std::size_t);
void writeFile(maptype&);

// do GUARD stuff