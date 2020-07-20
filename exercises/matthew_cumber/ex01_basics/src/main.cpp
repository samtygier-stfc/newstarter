/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

/*
  Currently assumes arg is a path to the file directly
*/

// TEST_PATH : /Users/Matt/STFC Placement/C++ Introduction/newstarter/exercises/matthew_cumber/ex01_basics/tst_files/Holmes.txt

char const PUNCTUATION[9] = {'.',',','?','\'','\"','!','(',')',':'};

/*
  Stores data for each unique word found in a txt file
  word : Stores the string of the word
  count : Stores the number of occurences of word in the file
*/
class UniqueWord
{
public:
  UniqueWord(std::string _word, int _count)
  {
    word = _word;
    count = _count;
  }

  std::string getWord() { return word; }
  void setWord(std::string _word) 
  {
    if(_word.length() == 0)
    {
      std::cout << "Invalid string, cannot be empty." << std::endl;
    } 
    else
    {
      word = _word; 
    }
  }

  int getCount() { return count; }
  void setCount(int _count)
  {
    if(_count < 0) 
    { 
      std::cout << "Invalid count, less than 0." << std::endl; 
    }
    else 
    { 
      count = _count; 
    }
  }
  void incrementCount()
  {
    ++count;
  }

private:
  std::string word;
  int count;
};

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
    // If not in vector already, create new word
    if(!InUniqueWords(uniqueWords,word))
    {
      auto newWord = UniqueWord(word,1);
      uniqueWords.push_back(newWord);
    }
  }

  // Print all words and counts
  for(auto &w : uniqueWords)
  {
    std::cout << w.getWord() << " - " << w.getCount() << std::endl;
  }

  // Close the file
  file.close();

  return 0;
}