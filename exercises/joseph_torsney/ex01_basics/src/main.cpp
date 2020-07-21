#include <iostream> 
#include <fstream>
#include <vector>
#include <map>
#include <bits/stdc++.h> 

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

/** Reads the contents of a .txt file at filepath
 * 
 * @param filepath the path to the file
 * @return std::string of the file contents
 */
std::string readFile(const std::string filepath)
{
  std::ifstream ifs(filepath);
  std::string text(
    (std::istreambuf_iterator<char>(ifs)),
    (std::istreambuf_iterator<char>())
  );
  return(text);
}

/** Removes punctuation from a string
 * 
 * @param str the string to process
 * @return std::string with no punctuation
 */
std::string removePunct(std::string str)
{
  for (int i = 0, len = str.size(); i < len; i++) {
    if (myIsPunct(str[i])) {
      // if this char is punctuation, reduce i by 1, remove it, and
      // reevaluate the string size.
      str.erase(i--, 1);
      len = str.size();
    }
  }
  return(str);
}

/** Splits a string by spaces and hyphens into a string vector.
 * 
 * @param s the string to split
 * @return std::vector<std::string> of 'words' contained in s.
 */
std::vector<std::string> split(const std::string& s)
{
  std::vector<std::string> ret;
  typedef std::string::size_type string_size;
  string_size i = 0;

  // process characters of s
  while (i != s.size()) {

    // ignore whitespace
    while(i != s.size() && (isspace(s[i]) || s[i] == '-')) {
      i++;
    }

    // otherwise, we are at the start of a word.
    string_size j = i;

    // find the position of the next space.
    while (j != s.size() && !(isspace(s[j]) || s[j] == '-')) {
      j++;
    }

    // If we have found a word
    if (i != j) {
      // copy substring from i, taking j - i chars.
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return(ret);
}

/** Counts the number of times a word appears (usage) in a given string vector.
 * 
 * @param words the string vector to count
 * @return std::map<std::string, int> maps each word to the number of usages.
 */
std::map<std::string, int> countWords(std::vector<std::string> words) {
  std::map<std::string, int> usage;
  std::map<std::string, int>::iterator it;

  for (int i = 0; i < words.size(); i++) {
    it = usage.find(words[i]);

    // if we haven't seen this world already, add it to the count.
    if (it == usage.end()) {
      usage.insert(std::make_pair(words[i], 1));
      continue;
    }
    it->second++;
  }
  return(usage);
}

/** Sorts a map by its second value descending into a pair vector.
 * 
 * @param map the map to sort
 * @return std::vector<std::pair<std::string, int>> sorted key, value pairs from map.
 */
std::vector<std::pair<std::string, int>> sortByValue(std::map<std::string, int> map) {

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

  return(v);
}

int main(int argc, const char** argv)
{ 
  std::string text = readFile(argv[1]);
  text = removePunct(text);

  std::vector<std::string> words = split(text);

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