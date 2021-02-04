/**
 * Skeleton main routine
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <map>

bool compareWordCount(std::pair<std::string, int> wordA, std::pair<std::string, int> wordB)
{
	return wordA.second > wordB.second;
}

int main(int, char **)
{
	//For now, just hard code the holmes file.
	std::string inputFileName = "C:/workdir/newstarter/exercises/tom_hampson/ex01_basics/testData/Holmes.txt";

  
	std::ifstream inputFile(inputFileName);

	if (!inputFile)
	{
		std::cout << "Unable to open file " << inputFileName << std::endl;
		return 1;
	}

	//Line of text from input source.
	std::string line;

	std::map<std::string, int> wordCounts;

	//Read file one line at a time, or until we reach a hyphen.
	while (std::getline(inputFile, line, '-'))
	{
		std::istringstream wordsInLine(line);

		std::string word;

		//Loop over words in the line, using whitespace as delimiter.
		while (wordsInLine >> word)
		{
			//Only consider words > 3 characters long.
			if (word.length() < 4)
			{
				continue;
			}
			//Remove all punctuation characters:
			//.,?'"!():
			//Need to escape several of them because they are special pattern
			//characters in regex expressions.
			std::regex specialCharacters("\\.|,|\\?|'|\"|!|\\(|\\)|:");
			std::string newWord = std::regex_replace(word, specialCharacters, "");

			//Check again for the length of the word because it will be shorter if punctuation was removed.
			if (newWord.length() < 4)
			{
				continue;
			}

			//Convert word to lower case.
			std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);

			//Increment the count of the word.
			wordCounts[newWord]++;
		}
	}

	//Container to store the word counts sorted by count.
	std::vector<std::pair<std::string, int>> sortedWordCounts;

	std::copy(wordCounts.begin(), wordCounts.end(), std::back_inserter(sortedWordCounts));

	std::sort(sortedWordCounts.begin(), sortedWordCounts.end(), compareWordCount);

	for (auto wordCount : sortedWordCounts) {
		std::cout << wordCount.first << ": " << wordCount.second << std::endl;
	}

	return 0;
    
}