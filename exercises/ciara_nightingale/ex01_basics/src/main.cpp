#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

// replaces the hypens with whitespace
bool replace_hyphens(std::string& word) {
  // std::cout << path[6] << std::endl;
  for (std::string::size_type i = 0; i != word.size(); ++i) {
    if (word[i] == '-') {
      word[i] = ' ';
      return true;
    }
  }
  return false;
}

// determine if a character is punctuation
bool is_punc(char const c) {
  static const std::string punc = ".,?\'\"!();";
  for (std::string::size_type i = 0; i != punc.size(); ++i) {
    if (c == punc[i]) {
      return true;
      break;
    }
  }
  return false;
}

// deal with punctuation and case sensitivity
void clean_word(std::string& word) {
  // remove characters if they are puctuation
  word.erase(remove_if(word.begin(), word.end(), is_punc), word.end());
  // convert characters to lowercase if they are uppercase
  transform(word.begin(), word.end(), word.begin(), tolower);
}

// convert a map to a vector of pairs
std::vector<std::pair<std::string, double>>
mapToVector(const std::map<std::string, double> &map) {
  return std::vector<std::pair<std::string, double>>(map.begin(), map.end());
}

// determine which pair is larger
bool compare(const std::pair<std::string, double> pair_1,
             const std::pair<std::string, double> pair_2) {
  return pair_1.second > pair_2.second;
}

void Vector_to_File(std::vector<std::pair<std::string, double>> counter,
                    std::string::size_type pad) {
  std::ofstream Results("text.txt");
  // writing the titles of the columns to the file
  Results << "Word" << std::string(pad - 3, ' ') << "Usage"
          << "\n\n";
  // write the results to the file, padded to make room for the longest word
  for (std::string::size_type i = 0; i != counter.size(); ++i) {
    Results << counter[i].first
            << std::string(pad + 1 - counter[i].first.size(), ' ')
            << counter[i].second << "\n";
  }
}

// std::ifstream Load_file()

void process_word(std::string& word, std::map<std::string, double>& counter, std::string::size_type& maxlen, std::string::size_type const word_length) {
		clean_word(word);
		maxlen = std::max(maxlen, word.size());
		if (word.size() > word_length) {
				++counter[word];
		}
}

void Unique(std::string::size_type const word_length) {
  std::map<std::string, double> counter;
  std::string path;
  std::cout << "enter file name: " << std::endl;
  std::cin >> path;
  std::ifstream in(path);
	if (!in) {
		std::cerr << "failed to load file! Incorrect file name specified";
	}
  std::string::size_type maxlen = 0;
  std::string word;
  while (in >> word) {
    if (replace_hyphens(word)) {
				std::stringstream stream_word(word);
				std::string word_1, word_2;
				stream_word >> word_1;
				stream_word >> word_2;
				process_word(word_1, counter, maxlen, word_length);
				process_word(word_2, counter, maxlen, word_length);
    }
		else {
				process_word(word, counter, maxlen, word_length);
		}
  }
  std::vector<std::pair<std::string, double>> count;
  count = mapToVector(counter);
  std::sort(count.begin(), count.end(), compare);
  Vector_to_File(count, maxlen);
}

int main() {
  Unique(4);
  return 0;
}
