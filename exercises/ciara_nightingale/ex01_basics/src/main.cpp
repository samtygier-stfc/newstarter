#include "Header.h"

/// Replaces the hyphens in a string with a whitespace character
bool replaceHyphens(std::string &word) {
  bool hyphenReplaced = false;
  // The whole word is checked rather than stopping at the first instance of a
  // hyphen
  for (std::string::size_type i = 0; i != word.size(); ++i) {
    // Check each character in the word
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

/// Determines if a character is punctuation
bool isPunc(char const &c) {
  static const std::string PUNC = ".,?\'\"!();:";
  for (std::string::size_type i = 0; i != PUNC.size(); ++i) {
    if (c == PUNC[i]) {
      return true;
      break;
    }
  }
  return false;
}

/// Removes the punctuation
void cleanWord(std::string &word) {
  // Remove characters if they are puctuation
  word.erase(remove_if(word.begin(), word.end(), isPunc), word.end());
  // Convert characters to lowercase if they are uppercase
  transform(word.begin(), word.end(), word.begin(), tolower);
}

/// Cleans the word using the cleanWord function, adds word to a map, stores the
/// no. of instances and caluclates the longest word
void processWord(std::string &word, std::map<std::string, int> &counter,
                 std::string::size_type &maxlen,
                 std::string::size_type const minWordLength) {
  cleanWord(word);
  if (word.size() > minWordLength) {
    ++counter[word];
    maxlen = std::max(maxlen, word.size());
    // Find the longest word.
    // Add the word to the map and the no. of appearances in the text.
  }
}

/// Converts a map to a vector of pairs to contain the unique words and their
/// number of usages
std::vector<std::pair<std::string, int>> const
mapToVector(const std::map<std::string, int> &map) {
  return std::vector<std::pair<std::string, int>>(map.begin(), map.end());
}

/// Determines which word has more usages
bool pairValueIsGreater(std::pair<std::string, int> const pair1,
                        std::pair<std::string, int> const pair2) {
  return pair1.second > pair2.second;
}

/// Prints the vector into a file
void vectortoFile(std::vector<std::pair<std::string, int>> const counter,
                  std::string::size_type const pad) {
  std::ofstream results("text.txt");
  // Write the titles of the columns to the file
  results << "Word" << std::string(pad - 3, ' ') << "Usage"
          << "\n\n";
  // Write the results to the file, padded to make room for the longest word
  for (std::string::size_type i = 0; i != counter.size(); ++i) {
    results << counter[i].first
            << std::string(pad + 1 - counter[i].first.size(), ' ')
            << counter[i].second << "\n";
  }
}

/// Caluclates the number of instances of unique words and prints it into a file
int uniqueWordCounter(std::string::size_type const minWordLength) {
  std::string path;
  std::cout << "enter file name: ";
  std::cin >> path;
  std::ifstream in(path);
  if (!in) {
    std::cerr << "failed to load file! Incorrect file name specified";
		return 1;
  }
  std::string word;
  std::map<std::string, int> counter;
  std::string::size_type maxlen = 0;
  while (in >> word) {
    if (replaceHyphens(word)) {
      // Ff the word contains a hyphen, remove the hyphen, split into words.
      std::stringstream streamWord(word);
      std::string moreWord = "";
      while (streamWord >> moreWord) {
        processWord(moreWord, counter, maxlen, minWordLength);
      }
      streamWord.clear();
    } else {
      processWord(word, counter, maxlen, minWordLength);
    }
  }
  // Vector containing the word and usage pairs from the map.
  auto count = mapToVector(counter);
  std::sort(count.begin(), count.end(), pairValueIsGreater);
  // Reorder the vector in descending order
  vectortoFile(count, maxlen); // Write the vector to a file
	return 0;
}

int main() {
  uniqueWordCounter(4);
  return 0;
}
