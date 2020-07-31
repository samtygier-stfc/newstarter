/**
 * Import statements
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <vector>
#include <map>

/** Returns a string filepath from user input
 *  @return string filepath
 */

std::string getInputFn() {
  std::cout << "Please enter the path of the file to be analysed" << std::endl;
  std::string fin;
  std::cin >> fin;
  return fin;
}

/** Split up a string and return a vector of words with
 *  len > 4, and converted to lower case
 *  @param s, reference to string s
 *  @param delim, character to use as delimiter
 * 
 *  @return vector of strings as split by chosen delimiter
 */

std::vector<std::string> splitByDelim(const std::string& s, const char delim) {
  
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  
  while (std::getline(tokenStream, token, delim)) {
    if(token.size() <= 4) {
      continue;
    }

    std::transform(token.begin(), token.end(), token.begin(),
    [](unsigned char c){ return std::tolower(c);});
    
    tokens.push_back(token);
  }

  return tokens;
}

/** Removes most puntuation from a string, and replaces hyphens
 *  with whitespace
 *  @param line - string to be depunctuated
 */

void depunctuate(std::string& line) {

  const int cRSize = 8;
  const char charRemove [cRSize] = {'.', ',', '?', '\'', '\"', '!', '(', ')'};

  std::replace_if(line.begin() , line.end(), 
  [] (const char& c) { return c == '-';},' ');

  line.erase(
    std::remove_if(line.begin() , line.end(), 
    [charRemove, cRSize] (const char& c) {
      for(int i = 0; i < cRSize; ++i) {
        if(c == charRemove[i]) {
          return true;
        }
      }
      return false;
    }),
  line.end());
}

/** Reads in lines from input file and returns a vector of
 *  depunctuated, lower case words of length >= 4. Prints error
 *  message and exits program if file not found
 *  @return vector of strings
 */

std::vector<std::string> inputToVector() {

  std::ifstream inFile;
  std::string fin = getInputFn();
  inFile.open(fin, std::ios::in);
  if (!inFile) {
    std::cout << "Unable to open the file.";
    exit(1);
  }

  std::string line;
  std::vector<std::string> words;
  while(std::getline(inFile, line)){
    depunctuate(line);
    std::vector<std::string> spLine = splitByDelim(line, ' ');
    words.insert(words.end(), spLine.begin(), spLine.end());
  }
  inFile.close();
  return words;
}

/** Populate a map with key=word, value=no of occurrences for an
 *  input vector of single word strings
 *  @param wordCountMap - map of strings to int occurrences
 *  @param words - vector of string words to be processed
 */ 

void fillMap(std::map<std::string, int>& wordCountMap, const std::vector<std::string>& words) {

  if(words.size() == 0){
    throw std::domain_error("Empty words vector");
  }

  for(auto& currentWord : words) {
    wordCountMap[currentWord] ++;
  }
}

/** Compare vector pairs by second (int) value
 *  @param a - string to be compared against
 *  @param b - string to compare
 * 
 *  @return boolean value to determing which is larger
 */ 
bool compareSecond(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
  return a.second > b.second;
}

/** Print to file in order the keys of a map by descending
 *  int value. The map is first assigned into a vector of pairs
 *  @param wordCountMap - map of string to int representing
 *  words/occurrences
 */

void printOrderedMap(std::map<std::string, int> wordCountMap) {

  std::vector<std::pair<std::string, int>> freq_vect( wordCountMap.begin(), wordCountMap.end() );
  sort(freq_vect.begin(), freq_vect.end(), compareSecond);

  std::ofstream outFile;
  outFile.open("Results.txt", std::ios::out);
  if (!outFile) {
    std::cout << "Unable to open the file.";
    exit(1);
  }
  size_t size = freq_vect.size();

  outFile << "Word           Usage" << std::endl << std::endl;
  for(int i = 0; i < size; i++) {
    std::string outString = freq_vect[i].first;
    size_t noToPad = 15 - outString.length();
    outFile << outString;
    for(int i = 0; i < noToPad; i++) {
      outFile << " ";
    }
    outFile << freq_vect[i].second << std::endl;
  }
  outFile.close();
}

/** Main function to operate and test the program
 *  @param int - command line arguments?
 *  @param char** - command line arguments?
 * 
 *  @return integer exit code value
 */

int main(int, char **)
{
  std::vector<std::string> words = inputToVector();

  std::map<std::string, int> wordCountMap;

  fillMap(wordCountMap, words);

  printOrderedMap(wordCountMap);

  return 0;
}