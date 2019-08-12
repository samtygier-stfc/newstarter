#include "main.h"

int main(int argc, char **argv) {
  // prompt user for filename
  std::cout << "Please enter the name of a file you wish to read: ";
  std::string filename;
  std::cin >> filename;

  // create map
  StrIntMap wordCounts;

  // declare file read boolean and unsigned max length
  bool readBool;
  std::size_t maxWordLength = 0;

  // read file
  try {
    readBool = readFile(filename, wordCounts, maxWordLength);
  } catch (const char *msg) {
    std::cerr << msg << std::endl;
    readBool = false;
  }

  // define lambda for comparison logic
  Comparator compFunctor = [](const StrIntPair &elem1,
                              const StrIntPair &elem2) {
    return elem1.second > elem2.second;
  };

  // declare vector
  std::vector<StrIntPair> orderedVector;

  // order words
  orderWords(wordCounts, orderedVector, compFunctor);

  // write file
  try {
    writeFile(orderedVector, maxWordLength, readBool);
  } catch (const char *msg) {
    std::cerr << msg << std::endl;
  }
}

/** Alters string to lower case
 *
 * @param word: string to be altered
 * @return word: string with all capitals lowered
 *
 */
std::string strTolower(std::string &word) {
  std::transform(word.begin(), word.end(), word.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return word;
}

/** Takes a string from which to clean specified characters from
 *	appearing after words
 *
 * @param word: string to be cleaned
 * @param cleanedWords: empty vector to store cleaned strings
 * @return void
 *
 */
void cleanWord(const std::string &word, std::vector<std::string> &cleanedWords) {
  static const std::regex STRING_REGEX("(\\B'\b|\b'\\B)|([\\.,:;!?()\"-]+)");
  auto first =
      std::sregex_token_iterator(word.begin(), word.end(), STRING_REGEX, -1);
  std::copy(first, std::sregex_token_iterator(),
            std::back_inserter(cleanedWords));
}

/** Loads a .txt file, checking for success. Subsequently reads the file
 *	storing all unique words and their numbers of occurrence
 *
 * @param filename: name of the input file to read
 * @param inputmap: map which will store all unique words and instances
 * @param minWordLength: default variable to limit the length of words
 * @return bool: check for read success
 *
 */
bool readFile(const std::string &filename, StrIntMap &inputmap,
              std::size_t &maxWordLength, const std::size_t minWordLength) {
  // attempt to open file
  std::ifstream inFile;
  inFile.open(filename + ".txt");
  if (!inFile) {
    throw "Unable to open requested file";
  } else {
    // read contents to map
    std::string word;
    while (inFile >> word) {
      // clean words
      std::vector<std::string> cleanedWords;
      std::string lowered = strTolower(word);
      cleanWord(lowered, cleanedWords);
      for (auto & cleanWord : cleanedWords) {
        if (cleanWord.size() > minWordLength) {
          ++inputmap[cleanWord];
          if (cleanWord.size() > maxWordLength) {
            maxWordLength = cleanWord.size();
          }
        }
      }
    }
    return true;
  }
}

/** Orders unique words in non-increasing order
 *
 * @param cleanedMap: map of cleaned words
 * @param outputVector: vector of pairs to stored ordered words
 * @param cmp: lambda function comparator
 * @return void
 *
 */
void orderWords(const StrIntMap &cleanedMap,
                std::vector<StrIntPair> &outputVector, const Comparator &cmp) {
  outputVector.reserve(cleanedMap.size());
  std::copy(cleanedMap.begin(), cleanedMap.end(),
            std::back_inserter(outputVector));
  std::sort(outputVector.begin(), outputVector.end(), cmp);
}

/** Determines whitespace formatting of output file
 *
 * @param str1: lhs string
 * @param maxWordLength: maximun length of strings
 * @return ws: string of appropriate number of white spaces
 *
 */
const std::string formatWhitespace(const std::string &str1,
                                   const std::size_t &maxWordLength) {
  std::string ws(maxWordLength - str1.length(), ' ');
  return ws;
}

/** Writes the results extracted from the map, into vector of pairs, to file
 *
 * @param orderedPair: ordered vector to write to file
 * @param maxWordLength: maximun length of strings
 * @param readBool: boolean to check file was read successfully
 * @return void
 *
 */
const void writeFile(const std::vector<StrIntPair> &orderedPair,
                     const std::size_t &maxWordLength, bool &readBool) {
  if (!readBool) {
    throw "Unable to write file";
  } else {
    std::ofstream outfile("word_counts.txt");
    std::string header1 = "Word", header2 = "Usage";
    outfile << header1 << formatWhitespace(header1, maxWordLength) << header2
            << "\n\n";
    for (auto it = orderedPair.begin(); it != orderedPair.end(); ++it) {
      outfile << it->first << formatWhitespace(it->first, maxWordLength) << it->second
              << '\n';
    }
  }
}