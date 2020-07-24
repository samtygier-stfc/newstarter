#include "UniqueWord.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>

/** Checks if a word already exists in the vector or words, then increments its count if found,
 * otherwise create a new word and add to vector
 *
 * @param uniqueWords The vector of existing unique words found
 * @param word The word being tested
 * @return No return value 
 */
void incrementCountOrAddNewWord(std::vector<UniqueWord> &uniqueWords, const std::string &word)
{
  // Attempt to find word in the vector uniqueWords
  auto it = std::find_if(uniqueWords.begin(), uniqueWords.end(), [&word](const UniqueWord &obj){return obj.getWord() == word;});

  // If not at end, then word has already been found in input file and is stored in the vector, so increment count
  if(it != uniqueWords.end())
    it->incrementCount();

  // Else the word has not been found previously, so create a new instance and add it to the vector 
  else uniqueWords.emplace_back(word,1);

  return;
}

/** Writes the unique words to an output file "UniqueWords.txt"
 * @param uniqueWords The vector of unique words to be written to the file
 * @return no return value
 */
void writeUniqueWordsToFile(const std::vector<UniqueWord> &uniqueWords)
{
  // Try to open the output file
  std::ofstream file("output.txt");
  if(!file.is_open())
  {
    std::cout << "Error opening file \"output.txt\", exiting ..." << std::endl;
    return;
  }

  // Header of output file
  file << "Word" << std::setw(FIELD_WIDTH) << "Usage" << std::endl << std::endl;

  int fieldWidth = 10;

  // To write words in descending order need to loop vector in reverse
  for(auto w = uniqueWords.rbegin(); w != uniqueWords.rend(); ++w)
  {
    // Format the output to align count values
    fieldWidth = FIELD_WIDTH-(int)w->getWord().length();
    if(fieldWidth <= 1) file << w->getWord() << " " << w->getCount() << std::endl;
    else file << w->getWord() << std::setw(fieldWidth) << w->getCount() << std::endl;
  }

  file.close();

  std::cout << "Words successfully saved in \"output.txt\"" << std::endl;

  return;
}

int main(int argc, char const **argv)
{

  std::string PATH = ""; // Store the path of the file to be read
  std::vector<UniqueWord> uniqueWords; // Stores words and counts as objects in a vector

  // Check a file path has been provided as an argument on cl
  if(argc < 2)
  {
    std::cout << "Please provide a path to the file to be read, or q to exit:" << std::endl;
    std::cin >> PATH;
    if(PATH == "q") return 0;
  }

  else PATH = argv[1];

  // Try to open file from given path
  std::ifstream file(PATH);
  if(!file.is_open())
  {
    std::cout << "Error opening file \"" + PATH + "\", exiting ..." << std::endl;
    return 1;
  }
  
  std::cout << "Reading file \"" + PATH + "\"" << std::endl;

  std::string word;

  // Loop file word by word, reads characters separated by spaces
  while(file >> word)
  {
    // Loop punctuation characters and erase them from word
    for(const char &p : PUNCTUATION)
      word.erase(std::remove(word.begin(), word.end(), p), word.end());

    // Convert all letters in word to lower case
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    // Now separate original word into words split by hyphens
    std::istringstream ss(word);
    std::string wordWithoutHyphens;
    while(std::getline(ss, wordWithoutHyphens, '-'))
    {
      // Skip words less than 5 characters
      if(wordWithoutHyphens.length() < 5) continue;

      // Else check if word has been found already and increment its count or create a new word
      incrementCountOrAddNewWord(uniqueWords,wordWithoutHyphens);
    }
  }

  file.close();

  // Sort Vector by count (In ascending order after this line)
  std::sort(uniqueWords.begin(),uniqueWords.end());

  // Print to terminal if added as argument
  if(argc > 2)
  {
    if(std::string(argv[2]) == "print")
    {
      for(auto w = uniqueWords.rbegin(); w != uniqueWords.rend(); ++w)
      {
        std::cout << w->getWord() << " - " << w->getCount() << std::endl;
      }
    }
  }

  writeUniqueWordsToFile(uniqueWords); // Found in "output.txt"

  return 0;
}