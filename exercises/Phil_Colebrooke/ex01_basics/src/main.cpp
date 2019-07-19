#include "main.h"

int main(int argc, char *argv[]) {
  const int CORRECT_NUMBER_ARGUMENTS{4};

  // checks that the user has provided the correct number of arguments
  if (argc != CORRECT_NUMBER_ARGUMENTS) {
    std::cerr
        << "Wrong number of arguments provided. "
           "Provide two filenames (input and output) and minimum word length."
        << "\n";
    return 1;
  }

  const std::string inputFilename{argv[1]};
  const std::string outputFilename{argv[2]};

  // the inputted min word length is converted to int
  const int minWordLength{atoi(argv[3])};

  bool success{false};
  std::map<std::string, int> wordsAndCounts;
  success = countWords(inputFilename, wordsAndCounts, minWordLength);

  if (success) {
    auto wordsSortedByUsage{orderByUsage(wordsAndCounts)};
    writeToFile(wordsSortedByUsage, outputFilename);

    return 0;
  }

  return 1;
}

/** Opens a text file and populates a map with every unique word in the file and
 * the number of times the word occurs
 *
 * @param filename The name of the input file to read
 * @param wordsAndCounts The map to be populated
 * @param minWordLength The minimum length of words to be added to the map
 * @return A boolean for whether or not the map was successfully populated
 *
 */
bool countWords(const std::string &inputFilename,
                std::map<std::string, int> &wordsAndCounts,
                const int &minWordLength) {

  std::ifstream file{inputFilename};

  // checks the file has been opened
  if (!file.is_open()) {
    std::cerr << "Unable to open input file for reading. Check that the file "
                 "exists and its name is spelt correctly."
              << "\n";
    return false;
  }

  // goes through each word in the file
  std::string word{};
  while (file >> word) {

    word = cleanUpWord(word);

    // only words of length at least the inputted minimum are added to the map
    if (word.length() >= minWordLength) {
      ++wordsAndCounts[word];
    }
  }

  file.close();

  return true;
}

/** Converts a word to lowercase and removes punctuation
 *
 * @param word The word to be cleaned up
 * @return The cleaned up word
 *
 */
std::string cleanUpWord(std::string &word) {
  std::string newWord{};
  const std::string PUNCTUATION{".,?'\"!():"};

  // iterates through each character in the word
  for (char &c : word) {

    // punctuation characters are discarded
    if (PUNCTUATION.find(c) == std::string::npos) {

      // converts uppercase characters to lowercase
      newWord += std::tolower(c);
    }
  }

  return newWord;
}

/** Converts the map to a vector of pairs and sorts it
 *
 * @param wordsAndCounts The map of words and number of occurences
 * @return The sorted vector of pairs of words and occurrecnes
 *
 */
std::vector<std::pair<int, std::string>>
orderByUsage(std::map<std::string, int> &wordsAndCounts) {

  std::vector<std::pair<int, std::string>> pairs{};

  // each word-usage pair in the map is added to the vector
  // as a usage-word pair (swapped for easy sorting)
  std::pair<int, std::string> pair;
  for (auto &word : wordsAndCounts) {
    pair.second = word.first;
    pair.first = word.second;

    pairs.push_back(pair);
  }

  // sorted in descending order of word usage
  std::sort(pairs.begin(), pairs.end(),
            std::greater<std::pair<int, std::string>>());

  return pairs;
}

/** Writes all of the word-usage pairs to an output file
 *
 * @param wordsAndCounts The vector of word-usage pairs to be written
 * @param outputFilename The name of the file to be written to
 *
 */
void writeToFile(std::vector<std::pair<int, std::string>> &wordsAndCounts,
                 const std::string &outputFilename) {
  std::ofstream outputFile{outputFilename};

  const int PADDED_WORD_LENGTH{32};

  // checks the file has been opened
  if (!outputFile.is_open()) {
    std::cerr << "Unable to open output file for writing."
              << "\n";
    return;
  }

  // headings are written to the file
  outputFile << "Word\t\t\t\tUsage\n\n";

  // iterates through the vector of pairs
  for (auto wordAndUsage : wordsAndCounts) {
    std::string word{wordAndUsage.second};

    // each word is padded with spaces to make the file look neat
    word.append(PADDED_WORD_LENGTH - word.length(), ' ');

    outputFile << word << wordAndUsage.first << "\n";
  }

  std::cout << "Output file successfully created."
            << "\n";

  outputFile.close();
}
