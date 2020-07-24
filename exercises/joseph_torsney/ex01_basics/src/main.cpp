#include <iostream> 
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

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
 * into a string vector split by whitespace, omitting punctuations
 * and strings less than length four.
 * 
 * @param filepath the path to the file
 * @return std::vector<std::string> of the file contents
 */
std::vector<std::string> processFile(const std::string& filepath)
{ 
  std::vector<std::string> words;
  std::ifstream file(filepath);

  std::string word;
  while(file >> word) {
    word = toLowerStr(removePunct(word));
    if (word.size() <= 4) {
      continue;
    }
    words.push_back(word);
  }
  
  return words;
}

/** Counts the number of times a word appears (usage) in a given string vector.
 * 
 * @param words the string vector to count
 * @return std::map<std::string, int> maps each word to the number of usages.
 */
std::map<std::string, int> countWords(const std::vector<std::string>& words) 
{
  std::map<std::string, int> usage;

  for (int i = 0; i < words.size(); i++) {
    usage[words[i]]++; 
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

  std::vector<std::string> words = processFile(argv[1]);

  // count and sort the usage
  auto usage = sortByValue(countWords(words));

  std::ofstream outdata;
  outdata.open(argv[2]);

  outdata << "Word\tUsage\n" << std::endl;
  // print everything out using the iterator :)
  for (auto it = usage.begin(); it != usage.end(); it++) {
    outdata << it-> first << "\t" << it -> second << std::endl;
  }
}