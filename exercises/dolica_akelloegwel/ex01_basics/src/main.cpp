#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>

bool ContainsDashes(std::string compositeWord)
{
	// Check if a word contains dashes
	return compositeWord.find("-") != std::string::npos;
}
std::vector<std::string> SplitWords(std::string compositeWord)
{
	// Declare a vector for the seperated words
	std::vector<std::string> words;

	// Declare a string for a segment
	std::string segment;

	// Convert the composite word to a stream
	std::stringstream wordStream(compositeWord);

	// Split the elements of the dream using the '-' character and place these in the vector
	while (std::getline(wordStream, segment, '-'))
	{
		// Ignore empty words
		if (segment.length() == 0)
			continue;

		// Add the word to the vector
		words.push_back(segment);
	}

	return words;
}
std::string PrepareWord(std::string rawWord)
{
	// Declare a string of punctuation characters
	std::string unwantedChars = ".,?'\"!():;";

	// Remove the unwanted characters from the string
	for (int i = 0; i < unwantedChars.length(); i++)
	{
		rawWord.erase(std::remove(rawWord.begin(), rawWord.end(), unwantedChars[i]), rawWord.end());
	}

	// Convert the word to lower case
	for (unsigned int i = 0; i < rawWord.length(); ++i)
	{
		rawWord[i] = std::tolower(rawWord[i]);
	}

	return rawWord;
}
void SaveWordCountToFile(std::map<std::string, int> wordMap, std::string outputFilename)
{
	// Declare a file stream for the results file
	std::ofstream outFile;

	// Open the results file 
	outFile.open(outputFilename);

	// Check that the file was opened successfully
	if (!outFile)
	{
		std::cout << "Error: Unable to open the file " << outputFilename << " for writing." << std::endl;
		exit(1);
	}

	// Declare a comparator for sorting the word map by word count
	auto cmp = [](const auto &p1, const auto &p2)
	{
		return p2.second < p1.second || !(p1.second < p2.second) && p1.first < p2.first;
	};

	// Declare a set for storing words by word count
	std::set < std::pair<std::string, size_t>, decltype(cmp)> s(wordMap.begin(), wordMap.end(), cmp);

	// Write the first few lines to the output file
	outFile << "Word" << "\t" << "Usage" << std::endl << std::endl;

	// Write the words and their count to the file using the set
	for (const auto &p : s)
	{
		outFile << p.first << "\t" << p.second << std::endl;
	}

	// Close the file
	outFile.close();

}
std::map<std::string, int> CountWords(std::string inputFilename)
{
	// Declare a hash table for storing the word counts
	std::map<std::string, int> wordMap;

	// Declare a stream for the text file
	std::ifstream inFile;

	// Declare a string for the words in the text 
	std::string words;

	// Attempt to open the file
	inFile.open(inputFilename);

	// Check that the file was opened successfully
	if (!inFile)
	{
		std::cout << "Error: Unable to open the file " << inputFilename << " for reading." << std::endl;
		exit(1);
	}

	// Traverse through the words in the file
	while (!inFile.eof())
	{
		// Store the word in a string
		inFile >> words;

		// Create a vector for storing the words after they've been split
		std::vector<std::string> splitWords;

		if (ContainsDashes(words))
		{
			// Remove dashes from the words if any are present
			splitWords = SplitWords(words);
		}
		else
		{
			// Place the single word in the vector when no dashes are present
			splitWords.push_back(words);
		}

		for (auto word = begin(splitWords); word != end(splitWords); ++word) 
		{
			// Make the word suitable for the word map by removing punctuation characters
			*word = PrepareWord(*word);

			// Check that the word has at least five characters
			if (word->length() <= 4)
				continue;

			// Place the word in the word map
			wordMap[*word]++;
		}
	}

	// Close the file
	inFile.close();

	return wordMap;
}
int main(int argc, char *argv[])
{
	// Declare a hash table for storing the word counts
	std::map<std::string, int> wordMap;

	// Declare a string for input/output filenames
	std::string inputFilename;
	std::string outputFilename;

	// Check that the correct number of arguments were given
	if (argc == 3)
	{
		inputFilename = argv[1];
		outputFilename = argv[2];
	}
	else
	{
		std::cout << "Error: Incorrect number of arguments given. Expected 3." << std::endl;
		exit(1);
	}

	// Pass the filename argument to the word count function
	wordMap = CountWords(inputFilename);

	// Pass the populated word map and the output filename to a function for writing these results to a file
	SaveWordCountToFile(wordMap,outputFilename);
}
