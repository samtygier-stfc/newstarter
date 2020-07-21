/**
 * Skeleton main routine
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include "UniqueWord.h"

// Default path for output file reading files from
std::string const PATH = "/Users/Matt/STFC Placement/C++ Introduction/newstarter/exercises/matthew_cumber/ex01_basics/";

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
  // Try to opne the output file
  std::ofstream file(PATH+"/src/output.txt");
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
    if(fieldWidth <= 0) file << w->getWord() << " " << w->getCount() << std::endl;
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
	if(argc < 2)
	{
		std::cout << "Please provide a path to the file to be read as a command line argument." << std::endl;
    std::cout << "Example usage:" << std::endl;
    std::cout << "  ./WordCounter \"example.txt\"" << std::endl;
    return 1;
	}

  // Try to open file from current directory, then try as if path passed as argument
  std::ifstream file(PATH+"/tst_files/"+argv[1]);
  if(!file.is_open())
  {
    file.open(argv[1]);
    if(!file.is_open())
    {
      std::cout << "Error opening file \"" + std::string(argv[1]) + "\", exiting ..." << std::endl;
      return 1;
    }
  }
  
  std::cout << "Reading file " + std::string(argv[1]) << std::endl;

  std::string word;

  // Loop file word by word, reads characters spearated by spaces
  while(file >> word)
  {
    // Skip words less than five characters
    if(word.length() < 5) continue;

    // Remove Punctuation, Convert all letters to lower case, and Remove hyphens
    for(int i = 0; i < word.length(); ++i)
    {
      // Erase letter if punctuation
      while(isPunctuation(word[i]))
      {
        word.erase(i,1);
        if(i >= word.length()) break; // Check not at end of word
      }

      if(i >= word.length()) break; // Check not at end of word

      // Separate hyphenated words
      if(word[i] == '-')
      {
        // Get first word before hyphen
        std::string subWord = word.substr(0,i);
        word.erase(0,i+1); // removing first word and first found hyphen

        i = 0; // Reset to beginning of string

        // Remove any extra hyphens following original
        while(word[i] == '-')
        {
          word.erase(i,1);
        }

        // Add the sub word if its length is greater than 4
        if(subWord.length() > 4)
        {
          if(!inUniqueWords(uniqueWords,subWord))
          {
            auto newWord = UniqueWord(subWord,1);
            uniqueWords.push_back(newWord);
          }
        }
      }

      if(i >= word.length()) break; // Check not at end of word

      // Convert next letter to lower case
      word[i] = tolower(word[i]);
    }

    // Final word may be less than 4 from hyphenated block so must do additionally check
    if(word.length() > 4)
    {
      // If not in vector of found words already, create new word
      if(!inUniqueWords(uniqueWords,word))
      {
        auto newWord = UniqueWord(word,1);
        uniqueWords.push_back(newWord);
      }
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
      // Print to terminal
      for(auto w = uniqueWords.rbegin(); w != uniqueWords.rend(); ++w)
      {
        // Format the output to align count values
        std::cout << w->getWord() << " - " << w->getCount() << std::endl;
      }
    }
  }

  writeUniqueWordsToFile(uniqueWords); // Found in "output.txt"

  return 0;
}