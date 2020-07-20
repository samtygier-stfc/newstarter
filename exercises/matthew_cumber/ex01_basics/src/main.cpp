/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

/*
  Currently assumes arg is a path to the file directly
*/

// TEST_PATH : /Users/Matt/STFC Placement/C++ Introduction/newstarter/exercises/matthew_cumber/ex01_basics/tst_files/Holmes.txt

char const PUNCTUATION[9] = {'.',',','?','\'','\"','!','(',')',':'};

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

private:
  std::string word;
  int count;
};

bool CharIsPunctuation(const char c)
{
  std::cout << c << std::endl;
  for (int i = 0; i < strlen(PUNCTUATION)-1; ++i)
  {
    std::cout << PUNCTUATION[i] << std::endl;
    if(c == PUNCTUATION[i]) return true;
  }

  std::cout << "Not Punct" << std::endl;
  return false;
}

int main(int argc, char const **argv)
{
	// Check a file path has been provided as an argument on cl
	if(argc != 2)
	{
		std::cout << "Please provide a path to the file to be read as a command line argument." << std::endl;
    std::cout << "Example usage:" << std::endl;
    std::cout << "  ./WordCounter \"example.txt\"" << std::endl;
    return 1;
	}

  std::cout << argv[1] << std::endl;

  // Attempt to open file
  std::ifstream file(argv[1]);
  if(!file.is_open())
  {
    std::cout << "Error opening file \"" + std::string(argv[1]) + "\", exiting ..." << std::endl;
    return 1;
  }

  UniqueWord word1 = UniqueWord("apple",1);
  UniqueWord word2 = UniqueWord("pear",3);

  std::cout << word1.getWord() << " - " << word1.getCount() << std::endl;
  std::cout << word2.getWord() << " - " << word2.getCount() << std::endl;

  file.close();
}