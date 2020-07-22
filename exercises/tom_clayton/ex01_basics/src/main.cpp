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

/**
 * Function to return a string filepath from user input
 */

std::string getInputFn() {
  std::cout << "Please enter the path of the file to be analysed" << std::endl;
  std::string fin;
  std::cin >> fin;
  return fin;
}

/**
 * Function to split up a string and return a vector of words with
 * len <4, and converted to lower case
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

/** Returns different integer values to classify an input char as
 *  either non-punctuation, puntuation to be removed or to be
 *  replaced with whitespace.
 *  Specified punctuation to be removed: .,?'"!()
 *  Specified punctuation to be replaced with whitespace: -
 * 
 *  @param c - Reference to the character in question
 *  @return int 0 if non-punct, 1 if punct to remove, 2 if punct to
 *  replace
 */

int specPunct(char c) {

  const char charRemove [8] = {'.', ',', '?', '\'', '\"', '!', '(', ')'};
  const char charReplace [1] = {'-'};

  auto findResult = std::find(std::begin(charRemove), std::end(charRemove), c);
  if(findResult != std::end(charRemove)) {
    return 1;
  }
  else {
    findResult = std::find(std::begin(charReplace), std::end(charReplace), c);
     if(findResult != std::end(charReplace)) {
      return 2;
      }
      else {
        return 0;
      }
  }
}

/**
 * Function to remove most punctuation, and replace hyphens with
 * whitespace
 */

void depunctuate(std::string& line) {

  std::replace_if(line.begin() , line.end(), 
  [] (const char& c) { return specPunct(c)==2;},' ');

  line.erase(
    std::remove_if(line.begin() , line.end(), 
    [] (const char& c) { return specPunct(c)==1;}),
  line.end());
  
}

/**
 * Function to read lines from an input and return a vector of
 * depunctuated, lower case words of length>=4
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

/**
 * Function to populate a map with key=word, value=no of
 * occurrences for an input vector of single word strings
 */ 

void fillMap(std::map<std::string, int>& wordCountMap, const std::vector<std::string>& words) {

  typedef std::vector<std::string>::size_type VecSz;
  VecSz words_size = words.size();
  if(words_size == 0){
    throw std::domain_error("Empty words vector");
  }

  for(VecSz i = 0; i < words_size; i++) {
    std::string currentWord = words[i];
    wordCountMap[currentWord] ++;
  }
}

/**
 * Function to compare vector pairs by second value
 */ 
bool compareSecond(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
  return a.second > b.second;
}

/**
 * Function to print to file in order the keys of a map by descending
 * int value. The map is first assigned into a vector of pairs
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

/**
 * Main function to operate and test the program
 */

int main(int, char **)
{
  std::vector<std::string> words = inputToVector();

  std::map<std::string, int> wordCountMap;

  fillMap(wordCountMap, words);

  printOrderedMap(wordCountMap);
}