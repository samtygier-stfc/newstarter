#include "UniqueWord.h"
#include <iostream>

/** Creates an instance of UniqueWord with given initial values
 * @param word the initial string to set m_ to for the object
 * @param count the initial count for the word (usually one)
 */
UniqueWord::UniqueWord(const std::string &word, const int &count)
{
  m_word = word;
  m_count = count;
}

/** Sets the value of m_word, cannot be empty
 * @param word The new string to set word to
 * @return No return value
 */
void UniqueWord::setWord(const std::string &word) 
{
  if(word.length() == 0)
  {
    std::cout << "Invalid string, cannot be empty." << std::endl;
  } 
  else
  {
    m_word = word; 
  }
  return;
}

/** Sets the value of m_count, cannot be less than 0
 * @param count The new int value to set count to
 * @return No return value
 */
void UniqueWord::setCount(const int &count)
{
  if(count < 0) 
  { 
    std::cout << "Invalid count, less than 0." << std::endl; 
  }
  else 
  { 
    m_count = count; 
  }
  return;
}

/** Increments m_count value by +1
 * @return No return value
 */
void UniqueWord::incrementCount() 
{ 
  ++m_count; 
  return;
}

/** Override definition of < operator to compare object member count value
 * @param w The second UniqueWord object which is being compared to the implied this object
 * @return A boolean true if count of this is less than count of w, false otherwise
 */
bool UniqueWord::operator<(const UniqueWord &w) const
{
  return getCount() < w.getCount();
}

bool UniqueWord::operator==(const std::string &w) const
{
  return getWord() == w;
}
