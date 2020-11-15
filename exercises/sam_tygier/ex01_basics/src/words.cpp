#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "words.h"

std::string normaliseWord(const std::string& word)
{
	std::string normWord = word; 
	std::transform(normWord.begin(), normWord.end(), normWord.begin(),
	[](unsigned char c){ return (unsigned char) std::tolower(c); });
	
	normWord.erase(std::remove_if(normWord.begin(), normWord.end(),
	[](unsigned char c){ return PUNCT.find(c) != std::string::npos; }), normWord.end());
	
	return normWord;
}

std::map<std::string, size_t> countWords(std::istream & input){
	std::map<std::string, size_t> counts;
	std::string curWord;

	while(input){
		char c = ' ';
		input.get(c);

		if(WORD_SEP.find(c) != std::string::npos){
			if(curWord.size()){
				auto normWord = normaliseWord(curWord);
				if(normWord.size() > 4){
					counts[normWord] += 1;
				}
				curWord = "";
			}
		} else {
			curWord += c;
		}
	}

	return counts;
}

std::vector<std::pair<std::string, size_t>> sortCounts(const std::map<std::string, size_t>& counts){
	std::vector<std::pair<std::string, size_t>> stats(counts.size());

	std::copy(counts.begin(), counts.end(), stats.begin());

	std::sort(stats.begin(), stats.end(),
	[](auto &leftWord, auto &rightWord){return leftWord.second > rightWord.second;});
	return stats;
}
