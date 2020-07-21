#include <iostream>
#include <string>
#include "UniqueWord.h"


UniqueWord::UniqueWord(std::string _word, int _count)
{
  word = _word;
  count = _count;
}

std::string UniqueWord::getWord() const { return word; }

void UniqueWord::setWord(std::string _word) 
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

int UniqueWord::getCount() const { return count; }

void UniqueWord::setCount(int _count)
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

void UniqueWord::incrementCount()
{
  ++count;
}

bool UniqueWord::operator<(const UniqueWord &w) const
{
  return getCount() > w.getCount();
}
