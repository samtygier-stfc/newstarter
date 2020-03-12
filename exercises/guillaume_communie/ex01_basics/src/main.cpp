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
const std::string INTERWORD_CHAR = " .,?'\"!():\n-";

/**
 * Print the program usage.
 */
void usage() {
  std::cout << "Usage: WordCounter <file_name>" << std::endl;
  exit(1);
}

/**
 * Check if a characters is an 'interword' character.
 * @param[in] c The character to test
 * @return      True if the character is an interword character
 */
bool isInterWord(char c) {
    return INTERWORD_CHAR.find(c) != std::string::npos;
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
    char character;
    std::string word;
    do {
        character = f.get();
        if (isalpha(character)) {
            word.push_back(tolower(character));
          } else if (isInterWord(character)) {
              if ((!word.empty()) && (word.size() > 4)) {
                  dictionnary[word]++;
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
    for (auto w : sorted_dic) {
        out_file << std::setw(15) << std::left
                 << w.first
                 << w.second
                 << std::endl;
    }

    out_file.close();
}

