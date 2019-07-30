#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

// replaces the hypens with whitespace - used in clean_word
bool replace_hyphens(std::string& word) {
  for (std::string::size_type i = 0; i != word.size(); ++i) {
		//check through each character in the word
    if (word[i] == '-') {
      word[i] = ' ';
      return true;
    }
  }
  return false;
}

// determine if a character is punctuation - used in clean_word
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

// deal with punctuation and case sensitivity - used in process_word
void clean_word(std::string& word) {
  // remove characters if they are puctuation
  word.erase(remove_if(word.begin(), word.end(), is_punc), word.end());
  // convert characters to lowercase if they are uppercase
  transform(word.begin(), word.end(), word.begin(), tolower);
}

//clean the words, count them and put them into the map
void processWord(std::string& word, std::map<std::string, int>& counter, std::string::size_type& maxlen, std::string::size_type const min_word_length) {
		clean_word(word);
		maxlen = std::max(maxlen, word.size()); //find the longest word.
		if (word.size() > min_word_length) {
				++counter[word];
				// add the word to the map and the no. of appearances in the text.
		}
}

// convert a map to a vector of pairs
std::vector<std::pair<std::string, int>>
mapToVector(const std::map<std::string, int> &map) {
  return std::vector<std::pair<std::string, int>>(map.begin(), map.end());
}

// determine which pair is greater
bool compare(const std::pair<std::string, int> pair_1,
             const std::pair<std::string, int> pair_2) {
  return pair_1.second > pair_2.second;
}

void Vector_to_File(std::vector<std::pair<std::string, int>> counter,
                    std::string::size_type pad) {
  std::ofstream Results("text.txt");
  // write the titles of the columns to the file
  Results << "Word" << std::string(pad - 3, ' ') << "Usage"
          << "\n\n";
  // write the results to the file, padded to make room for the longest word
  for (std::string::size_type i = 0; i != counter.size(); ++i) {
    Results << counter[i].first
            << std::string(pad + 1 - counter[i].first.size(), ' ')
            << counter[i].second << "\n";
  }
}

//counts the number of unique words no. of instances
void uniqueWordCounter(std::string::size_type const min_word_length) {
  std::map<std::string, int> counter;
  std::string path;
	std::string::size_type maxlen = 0;
	std::string word;
	std::cout << "enter file name: ";
	std::cin >> path;
	std::ifstream in(path);
	if (!in) {
			std::cerr << "failed to load file! Incorrect file name specified";
	}
  
  while (in >> word) {
    if (replace_hyphens(word)) {
				//if the word contains a hyphen, remove the hyphen, split into two words.
				std::stringstream stream_word(word);
				std::string word_1, word_2;
				stream_word >> word_1;
				stream_word >> word_2;
				processWord(word_1, counter, maxlen, min_word_length);
				processWord(word_2, counter, maxlen, min_word_length);
    }
		else {
				processWord(word, counter, maxlen, min_word_length);
		}
  }
	//vector containing the word and usage pairs from the map.
  std::vector<std::pair<std::string, int>> count;
  count = mapToVector(counter);
  std::sort(count.begin(), count.end(), compare); // reorder the vector in descending order
  Vector_to_File(count, maxlen); // write the vector to a file
}

int main() {
  uniqueWordCounter(4);
  return 0;
}