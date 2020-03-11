/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <iomanip>
#include <set>

const std::string RESULTS_FILENAME("word_counts.data");

/**
 * Print the program usage.
 */
void usage(void) {
  std::cout << "Usage: WordCounter <file_name>" << std::endl;
  exit(1);
}

/**
 * Check if a characters is an 'interword' character.
 * @param[in] c The character to test
 * @return      True if the character is an interword character
 */
bool isInterWord(int c) {
    return (c == ' ') || (c == '.') || (c == ',') || (c == '?') || (c == '\'')
        || (c == '"') || (c == '!') || (c == '(') || (c == ')') || (c == ':')
        || (c == '\n') || (c== '-');
}

int main(int argc, char *argv[])
{
    // check arguments
    if (argc != 2)
        usage();

    // try to open the file
    std::ifstream f(argv[1]);
    if (!f.good()) {
        std::cout << "Error: please provide a valid file path." << std::endl;
        usage();
    }

    // read the words
    std::map<std::string, int> dictionnary;
    int character;
    std::string word;
    do {
        character = f.get();
        if (isalpha(character)) {
            word.push_back((char) tolower(character));
          } else if (isInterWord(character)) {
              if ((!word.empty()) && (word.size() > 4)) {
                  auto it = dictionnary.find(word);
                  if (it != dictionnary.end()) {
                      it->second++;
                  } else {
                      dictionnary[word] = 1;
                  }
              }
              word.clear();
          }
    } while (character != EOF);
    f.close();

    // sort the results by descending occurence
    typedef std::pair<std::string, int> element;
    std::set<element, bool(*)(element, element)>
        sorted_dic(dictionnary.begin(), dictionnary.end(),
                   [](element e1, element e2) -> bool {
                       if (e1.second == e2.second)
                           return e1.first < e2.first;
                       else
                           return e1.second > e2.second;
                   });

    // print the results
    std::ofstream out_file(RESULTS_FILENAME);
    out_file << std::setw(15) << std::left;
    out_file << "Words" << "Usage" << std::endl;
    for (auto it = sorted_dic.begin() ; it != sorted_dic.end() ; it++) {
        out_file << std::setw(15) << std::left
                 << it->first
                 << it->second
                 << std::endl;
    }

    out_file.close();
}

