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
using namespace std;

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

std::vector<std::string> splitByDelim(const std::string& s, char delim) {
  
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  
  while (std::getline(tokenStream, token, delim)) {
    if(token.size() < 4) {
      continue;
    }

    std::transform(token.begin(), token.end(), token.begin(),
    [](unsigned char c){ return std::tolower(c);});
    
    tokens.push_back(token);
    //cout << token << endl;
  }

  return tokens;
}

/**
 * Function to replace puncuation with whitespace in a string
 */

void depunctuate(std::string& line) {

  std::replace_if(line.begin() , line.end(), 
  [] (const char& c) { return std::ispunct(c) ;},' ');
}

/**
 * Function to read lines from an input and return a vector of
 * depunctuated, lower case words of length>=4
 */

std::vector<std::string> inputToVector() {

  std::ifstream inFile;
  std::string fin = getInputFn();
  inFile.open(fin, ios::in);
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

void fillMap(std::map<std::string, int>& wordCountMap, std::vector<std::string>& words) {

  typedef vector<std::string>::size_type vec_sz;
  vec_sz words_size = words.size();
  if(words_size == 0){
    throw domain_error("Empty words vector");
  }

  for(vec_sz i = 0; i < words_size; i++) {
    std::string currentWord = words[i];
    wordCountMap[currentWord] ++;
  }
}

/**
 * Function to compare vector pairs by second value
 */ 
bool compareSecond(const pair<std::string, int> &a, const pair<std::string, int> &b) {
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
  outFile.open("Results.txt", ios::out);
  if (!outFile) {
    std::cout << "Unable to open the file.";
    exit(1);
  }
  size_t size = freq_vect.size();

  outFile << "Word           Usage" << endl << endl;
  for(int i = 0; i < size; i++) {
    std::string outString = freq_vect[i].first;
    size_t noToPad = 15 - outString.length();
    outFile << outString;
    for(int i = 0; i < noToPad; i++) {
      outFile << " ";
    }
    outFile << freq_vect[i].second << endl;
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