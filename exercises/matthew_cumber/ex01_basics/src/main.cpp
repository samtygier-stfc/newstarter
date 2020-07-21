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

/*
  Currently assumes arg is a path to the file directly
*/

// TEST_PATH : /Users/Matt/STFC Placement/C++ Introduction/newstarter/exercises/matthew_cumber/ex01_basics/tst_files/Holmes.txt

// Return true if word exixts, false otherwise
bool InUniqueWords(std::vector<UniqueWord> &uniqueWords,std::string word)
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

// Return true if given letter is one of predefined punctuation characters
bool IsPunctuation(const char letter)
{
  for(int i = 0; i < PUNCTUATION_COUNT; ++i)
  {
    if(letter == PUNCTUATION[i]) return true;
  }

  return false;
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
    // Remove Punctuation
    for(int i = 0; i < word.length(); ++i)
    {
      if(IsPunctuation(word[i])) word.erase(i);
    }

    // Separate Hyphen words

    // Convert to lower case
    for (char &letter : word)
    {
      letter = tolower(letter);
    }

    // If not in vector already, create new word
    if(!InUniqueWords(uniqueWords,word))
    {
      auto newWord = UniqueWord(word,1);
      uniqueWords.push_back(newWord);
    }
  }

  // Sort Vector by count
  std::sort(uniqueWords.begin(),uniqueWords.end());

  for(auto &w : uniqueWords)
  {
    std::cout << w.getWord() << " - " << w.getCount() << std::endl;
  }

  file.close();

  return 0;
}