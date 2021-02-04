/**
 * Read text file and count instances of words with >= 4 letters, then save the information to a file.
 * 
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <map>

/** Compare number of instances of two words.
 * @param wordA 
 * @param wordB 
 * @return True if wordA has higher count than wordB
*/
bool compareWordCount(const std::pair<std::string, int>& wordA, const std::pair<std::string, int>& wordB)
{
	return wordA.second > wordB.second;
}

/** Write the words and their counts to file.
 *
 * @param wordCounts 
 * @param fileName 
 * @return False if the file doesn't open.
*/
bool writeWordCountsToFile(std::vector<std::pair<std::string, int>>& wordCounts, const std::string& fileName)
{
	std::ofstream outputFile(fileName);

	if (!outputFile)
	{
		return false;
	}

	outputFile << "Word " << "Usage" <<std::endl;

	for (auto wordCount : wordCounts)
	{
		outputFile << wordCount.first << " " << wordCount.second << std::endl;
	}

	outputFile.close();

	return true;
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

	if (!writeWordCountsToFile(sortedWordCounts, "output.txt"))
	{
		std::cout << "Error encountered while writing file.";
		return 1;
	}

	return 0;
    
}