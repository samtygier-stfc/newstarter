#pragma once

#include <string>

// Gap between writing in output file
const int FIELD_WIDTH = 15;

// Punctuation to be removed from the text
const char PUNCTUATION[9] = {'.',',','?','\'','\"','!','(',')',':'};

/*
 * Stores data for each unique word found in a txt file
 * m_word : Stores the string of the word
 * m_count : Stores the number of occurrences of word in the file
 */
class UniqueWord
{
public:
  /// Constructor of UniqueWord with given word and count
  UniqueWord(const std::string &word, const int &count);

  /// Getter for the string word
  inline std::string getWord() const { return m_word; }

  /// Setter for the string word
  void setWord(const std::string &word);

  /// Getter for the int count
  inline int getCount() const { return m_count; }

  /// Setter for int count
  void setCount(const int &count);

  /// Increments the value of count by 1
  void incrementCount();

  /// Overload "<" operator used in std::sort call to sort objects UniqueWord by count in descending order
  bool operator<(const UniqueWord &w) const;

private:
  std::string m_word;
  int m_count;
};