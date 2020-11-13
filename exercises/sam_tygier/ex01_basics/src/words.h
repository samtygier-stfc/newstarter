#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

/// Characters used for splitting words
const std::string WORD_SEP = " -\n\r";

/// Punctuation characters removed from words
const std::string PUNCT = ".,?'\"!():";

/**
 * Normalises a word by removing punctuation and converting to lower case
 */
std::string normaliseWord(const std::string& word);

/**
 * Takes an input stream and returns a map containing the unique words
 * and their counts
 */
std::map<std::string, size_t> countWords(std::istream & input);

/**
 * Takes map of word and counts and returns a vector in descending order
 */
std::vector<std::pair<std::string, size_t>> sortCounts(const std::map<std::string, size_t>& counts);

#endif
