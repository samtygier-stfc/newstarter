#include <iostream>
#include <string>
#include "UniqueWord.h"

/** Creates an instance of UniqueWord with given initial values
 * @param _word the initial string to set word to for the object
 * @param _count the initial count for the word (usually one)
 */
UniqueWord::UniqueWord(std::string _word, int _count)
{
  word = _word;
  count = _count;
}

/** Sets the value of word, cannot be empty
 * @param _word The new string to set word to
 * @return No return value
 */
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
  return;
}

/** Sets the value of count, cannot be less than 0
 * @param _count The new int value to set count to
 * @return No return value
 */
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
  return;
}

/** Increments the count value by +1
 * @return No return value
 */
void UniqueWord::incrementCount() 
{ 
  ++count; 
  return;
}

/** Overide definition of < operator to compare object member count value
 * @param w The second UniqueWord object which is being compared to the implied this object
 * @return A boolean true if this->count is less than w.count, false otherwsie
 */
bool UniqueWord::operator<(const UniqueWord &w) const
{
  return getCount() < w.getCount();
}
