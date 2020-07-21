/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <ctype.h>
#include "UniqueWord.h"

// TEST_PATH : /Users/Matt/STFC Placement/C++ Introduction/newstarter/exercises/matthew_cumber/ex01_basics/tst_files/Holmes.txt

/** Tests if a word has already been found the increments it's count
 * @param uniqueWords The vector of existing unique words found
 * @param word The word that is being tested
 * @return A boolean, true if a word already exists, false otherwise
 */
bool inUniqueWords(std::vector<UniqueWord> &uniqueWords,std::string word)
{
  // Loop unique words, if word exists increment it's count
  for(auto &w : uniqueWords)
  {
    if(word == w.getWord())
    {
      w.incrementCount();
      return true;
    }
  }

  return false;
}

/** Tests if a letter is one of the predefined punctuation characters
 * @param letter The letter which is being tested
 * @return A boolean, true if a letter is a punctuation character, false otherwise
 */
bool isPunctuation(const char letter)
{
  for(int i = 0; i < PUNCTUATION_COUNT; ++i)
  {
    if(letter == PUNCTUATION[i]) return true;
  }

  return false;
}

/** Writes the unique words to an output file "UniqueWords.txt"
 * @param uniqueWords The vector of unique words to be written to the file
 * @return no return value
 */
void writeUniqueWordsToFile(std::vector<UniqueWord> const uniqueWords)
{
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
    fieldWidth = FIELD_WIDTH-w->getWord().length();
    if(fieldWidth < 0) file << w->getWord() << "          " << w->getCount() << std::endl;
    else file << w->getWord() << std::setw(fieldWidth) << w->getCount() << std::endl;
  }

  file.close();

  std::cout << "Words successfuly saved in \"output.txt\"" << std::endl;

  return;
}

int main(int argc, char const **argv)
{
  std::vector<UniqueWord> uniqueWords; // Stores words and counts as objects in a vector

	// Check a file path has been provided as an argument on cl
	if(argc != 2)
	{
		std::cout << "Please provide a path to the file to be read as a command line argument." << std::endl;
    std::cout << "Example usage:" << std::endl;
    std::cout << "  ./WordCounter \"example.txt\"" << std::endl;
    return 1;
	}

  // Attempt to open file
  std::ifstream file(argv[1]);
  if(!file.is_open())
  {
    std::cout << "Error opening file \"" + std::string(argv[1]) + "\", exiting ..." << std::endl;
    return 1;
  }

  std::string word;

  // Loop file word by word, reads characters spearated by spaces
  while(file >> word)
  {
    // Skip words less than four characters
    if(word.length() < 4) continue;

    // Remove Punctuation, Convert all letters to lower case
    for(int i = 0; i < word.length(); ++i)
    {
      // Erase letter if punctuation
      while(isPunctuation(word[i]))
      {
        word.erase(i,1);
        if(i >= word.length()) break; // Check not at end of word
      }

      if(i >= word.length()) break; // Check not at end of word

      // Convert next letter to lower case
      word[i] = tolower(word[i]);
    }

    // Separate Hyphen words

    // If not in vector of found words already, create new word
    if(!inUniqueWords(uniqueWords,word))
    {
      auto newWord = UniqueWord(word,1);
      uniqueWords.push_back(newWord);
    }
  }

  file.close();

  // Sort Vector by count (In ascending order after this line)
  std::sort(uniqueWords.begin(),uniqueWords.end());

  // Print to terminal
  for(auto &w : uniqueWords)
  {
    std::cout << w.getWord() << " - " << w.getCount() << std::endl;
  }

  writeUniqueWordsToFile(uniqueWords);

  return 0;
}