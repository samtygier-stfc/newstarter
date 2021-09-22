#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

constexpr int MIN_WORD_LEN{5};

/**
 * Convert a string to it's lower case version.
 * @param string String to convert
 */
void toLower(std::string &string) {
    std::for_each(string.begin(), string.end(), [](char &c) {c = ::tolower(c);} );
}

/**
 * Check if a given character not allowed in a word, most punctuation.
 * @param cha Character to check
 * @return True if invalid, False otherwise
 */
bool isInvalid(char &cha) {
    const std::string invalid = ".,?'\"!():";
    return !(isalnum(cha) || std::find(invalid.begin(), invalid.end(), cha) == invalid.end());
}

/**
 * Remove invalid characters from a string.
 * @param word Word to clean up.
 */
void cleanWord(std::string &word){
    word.erase(std::remove_if(word.begin(), word.end(), isInvalid), word.end());
    toLower(word);
}

/**
 * Count the number of instances of each word in the input, give they are longer than MIN_WORD_LEN
 * @param countMap Map of counts of each word.
 * @param input Stream of text to count, splits on whitespace and on hyphens.
 */
void countWords(std::map<std::string, int> &countMap, std::ifstream &input){
    std::string word;
    while(input >> word) {
        cleanWord(word);
        if(std::find(word.begin(), word.end(), '-') != word.end()) {
            std::string splitWord;
            // Stick a hyphen on the end to make sure the last hyphenated word is added.
            word += "-";
            for(char &c : word) {
                if (c == '-') {
                    if (splitWord.length() > MIN_WORD_LEN) {
                        countMap[splitWord]++;
                    }
                    splitWord = "";
                } else {
                    splitWord += c;
                }
            }
        } else {
            if(word.length() > MIN_WORD_LEN) {
                countMap[word]++;
            }
        }
    }
}

/**
 * Sort the map of word counts into a vector of pairs. Most frequent words first.
 * @param countMap Map of word counts.
 * @return Sorted vector of pairs (descending by frequency)
 */
std::vector<std::pair<std::string, int>> getSortedVector(const std::map<std::string, int> &countMap) {
    std::vector<std::pair<std::string, int>> pairs;
    std::pair<std::string, int> pair;
    for(auto const &word : countMap) {
        pair.first = word.first;
        pair.second = word.second;
        pairs.push_back(pair);
    }
    std::sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {return a.second > b.second;});
    return pairs;
}

/**
 * Export the results to a given file.
 * @param sorted
 */
int outputResults(const std::vector<std::pair<std::string, int>> &sorted){
    std::cout << "Enter output path: \n";
    std::string outPath;
    std::cin >> outPath;
    std::ofstream outputFile{outPath.c_str()};
    if(outputFile.is_open()) {
        for (const auto &pair: sorted) {
            outputFile << pair.first << "\t\t" << pair.second << "\n";
        }
        outputFile.close();
        return 0;
    } else {
        std::cout << "Invalid output file.\n";
        return 1;
    }
}

/**
 * Main to start
 * @return 0 on success, 1 on failure.
 */
int main() {
    std::cout << "Enter file path.\n";
    std::string path;
    std::cin >> path;
    std::ifstream inputFile{path.c_str()};



    std::map<std::string, int> counts;

    countWords(counts, inputFile);

    if (inputFile.is_open()) {
        countWords(counts, inputFile);
        inputFile.close();
        return outputResults(getSortedVector(counts));
    } else {
        std::cout << "Invalid input file.";
        return 1;
    }
}



