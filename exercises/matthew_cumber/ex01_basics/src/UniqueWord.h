#pragma once

// Punctuation to be removed from the text
int const PUNCTUATION_COUNT = 9;
char const PUNCTUATION[PUNCTUATION_COUNT] = {'.',',','?','\'','\"','!','(',')',':'};

/*
  Stores data for each unique word found in a txt file
  word : Stores the string of the word
  count : Stores the number of occurences of word in the file
*/
class UniqueWord
{
public:
  UniqueWord(std::string _word, int _count);

  std::string getWord() const;
  void setWord(std::string _word);

  int getCount() const;
  void setCount(int _count);
  void incrementCount();

  // Overload "<" operator used in std::sort call to sort objects UniqueWord by count in descending order
  bool operator<(const UniqueWord &w) const;

private:
  std::string word;
  int count;
};