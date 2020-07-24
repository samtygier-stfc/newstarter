#include <iostream> 
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

/** Checks whether a character is punctuation
 * 
 * @param c 
 * @return true if c is punctuation
 * @return false otherwise
 */
bool myIsPunct(char c) {
  return(
    c == '.' ||
    c == ',' ||
    c == '?' ||
    c == '\'' ||
    c == '\"' ||
    c == '!' ||
    c == ')' ||
    c == '('
  );
}

/** Transforms a string to lower case.
 * 
 * @param str the string to transform
 * @return std::string the string in lower case
 */
std::string toLowerStr(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), 
    [](unsigned char c){ return std::tolower(c); }
  );

  return str;
}

/** Removes punctuation from a string
 * 
 * @param str the string to process
 * @return std::string with no punctuation
 */
std::string removePunct(std::string str)
{
  str.erase(std::remove_if(str.begin(), str.end(), &myIsPunct), str.end());
  return str;
}

/** Reads the contents of a .txt file at filepath 
 * into a map of word usage, omitting punctuation and case.
 * 
 * @param filepath the path to the file
 * @return std::map<std::string, int> of the usage of each word
 */
std::map<std::string, int> wordUsageFromFile(const std::string& filepath)
{ 
  std::map<std::string, int> usage;
  std::ifstream file(filepath);

  // read characters between whitespace
  std::string word;
  while(file >> word) {
    // split word by hyphens
    std::istringstream ss(word);
    std::string wordWithoutHyphens;
    while(std::getline(ss, wordWithoutHyphens, '-')); 

    wordWithoutHyphens = toLowerStr(removePunct(wordWithoutHyphens));

    if (wordWithoutHyphens.size() <= 4) {
      continue;
    }
 
    usage[wordWithoutHyphens]++;
  }
  
  return usage;
}

/** Sorts a map by its second value descending into a pair vector.
 * 
 * @param map the map to sort
 * @return std::vector<std::pair<std::string, int>> sorted key, value pairs from map.
 */
std::vector<std::pair<std::string, int>> sortByValue(std::map<std::string, int> map) 
{
  // declare and create a vector of pairs
  std::vector<std::pair<std::string, int>> v;
  for (auto& it : map) {
    v.push_back(it);
  }

  // then, the vector by the second value descending.
  std::sort(v.begin(), v.end(), 
    [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
      return(a.second > b.second);
    }
  );

  return v;
}

int main(int argc, const char** argv)
{ 
  // check correct command line arguments
  if (argc < 3) {
    std::cout 
      << "Incorrect number of args\nUsage: ./WordCounter <input filepath> <output filepath>"
      << std::endl;
    return 0;
  }

  auto usage = wordUsageFromFile(argv[1]);

  // count and sort the usage map into vector of pairs
  auto usageVector = sortByValue(usage);

  std::ofstream outdata;
  outdata.open(argv[2]);

  outdata << "Word\tUsage\n" << std::endl;
  // print everything out using the iterator :)
  for (auto it = usage.begin(); it != usage.end(); it++) {
    outdata << it->first << "\t" << it ->second << std::endl;
  }
}