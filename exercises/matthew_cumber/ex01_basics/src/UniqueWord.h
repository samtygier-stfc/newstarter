#pragma once

// Gap between writing in output file
int const FIELD_WIDTH = 15;

// Punctuation to be removed from the text
int const PUNCTUATION_COUNT = 9;
char const PUNCTUATION[PUNCTUATION_COUNT] = {'.',',','?','\'','\"','!','(',')',':'};

/*
 * Stores data for each unique word found in a txt file
 * word : Stores the string of the word
 * count : Stores the number of occurences of word in the file
 */
class UniqueWord
{
public:
  /// Constructor of UniqueWord with given word and count
  UniqueWord(std::string _word, int _count);

  /// Getter for the string word
  inline std::string getWord() const { return word; }

  /// Setter for the string word
  void setWord(std::string _word);

  /// Getter for the int count
  inline int getCount() const { return count; }

  /// Setter for int count
  void setCount(int _count);

  /// Increments the value of count by 1
  void incrementCount();

  /// Overload "<" operator used in std::sort call to sort objects UniqueWord by count in descending order
  bool operator<(const UniqueWord &w) const;

private:
  std::string word;
  int count; // The number of occurences of word in a text file
};