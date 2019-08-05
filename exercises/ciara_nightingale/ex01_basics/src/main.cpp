#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

// replaces the hypens with whitespace
bool replaceHyphens(std::string &word) {
  bool hyphenReplaced = false; // so the whole word is checked rather than stopping at the
                     // first instance of a hyphen
  for (std::string::size_type i = 0; i != word.size(); ++i) {
    // check through each character in the word
    if (word[i] == '-') {
      word[i] = ' ';
      hyphenReplaced = true;
    }
  }
  if (hyphenReplaced) {
    return hyphenReplaced;
  }
  return false;
}

// determine if a character is punctuation - used in clean_word
bool isPunc(char& const c) {
  static const std::string PUNC = ".,?\'\"!();:";
  for (std::string::size_type i = 0; i != PUNC.size(); ++i) {
    if (c == PUNC[i]) {
      return true;
      break;
    }
  }
  return false;
}

// deal with punctuation and case sensitivity - used in process_word
void cleanWord(std::string &word) {
  // remove characters if they are puctuation
  word.erase(remove_if(word.begin(), word.end(), isPunc), word.end());
  // convert characters to lowercase if they are uppercase
  transform(word.begin(), word.end(), word.begin(), tolower);
}

// clean the words, count them and put them into the map
void processWord(std::string &word, std::map<std::string, int> &counter,
                 std::string::size_type &maxlen,
                 std::string::size_type const min_word_length) {
  cleanWord(word);
  maxlen = std::max(maxlen, word.size()); // find the longest word.
  if (word.size() > min_word_length) {
    ++counter[word];
    // add the word to the map and the no. of appearances in the text.
  }
}

// convert a map to a vector of pairs
std::vector<std::pair<std::string, int>> const
mapToVector(const std::map<std::string, int> &map) {
  return std::vector<std::pair<std::string, int>>(map.begin(), map.end());
}

// determine which pair is greater
bool pairValueIsGreater(std::pair<std::string, int> const pair_1,
             std::pair<std::string, int> const pair_2) {
  return pair_1.second > pair_2.second;
}

void vectortoFile(std::vector<std::pair<std::string, int>> const counter,
                    std::string::size_type const pad) {
  std::ofstream results("text.txt");
  // write the titles of the columns to the file
  results << "Word" << std::string(pad - 3, ' ') << "Usage"
          << "\n\n";
  // write the results to the file, padded to make room for the longest word
  for (std::string::size_type i = 0; i != counter.size(); ++i) {
    results << counter[i].first
            << std::string(pad + 1 - counter[i].first.size(), ' ')
            << counter[i].second << "\n";
  }
}

// counts the number of unique words no. of instances
void uniqueWordCounter(std::string::size_type const min_word_length) {
  std::string path;
  std::cout << "enter file name: ";
  std::cin >> path;
  std::ifstream in(path);
  if (!in) {
    std::cerr << "failed to load file! Incorrect file name specified";
  }
	std::string word;
	std::map<std::string, int> counter;
	std::string::size_type maxlen = 0;
  while (in >> word) {
    if (replaceHyphens(word)) {
      // if the word contains a hyphen, remove the hyphen, split into words.
      std::stringstream streamWord(word);
      std::string moreWord = "";
      while (streamWord >> moreWord) {
        processWord(moreWord, counter, maxlen, min_word_length);
      }
      streamWord.clear();
    } else {
      processWord(word, counter, maxlen, min_word_length);
    }
  }
  // vector containing the word and usage pairs from the map.
  auto count = mapToVector(counter);
  std::sort(count.begin(), count.end(),
            pairValueIsGreater);            // reorder the vector in descending order
  vectortoFile(count, maxlen); // write the vector to a file
}

int main() {
  uniqueWordCounter(4);
  return 0;
}
