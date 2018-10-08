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

		words.push_back(segment);
	}

	// Return the vector of words that have been seperated by dashes
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

	// Return a word that is now suitable for the word map
	return rawWord;
}
void SaveWordCountToFile(std::map<std::string, int> wordMap)
{
	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
		[](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2)
	{
		return elem1.second > elem2.second;
	};

	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
		wordMap.begin(), wordMap.end(), compFunctor);

	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	for (std::pair<std::string, int> element : setOfWords)
		std::cout << element.first << " :: " << element.second << std::endl;

}
std::map<std::string, int> CountWords(std::string asciiFilename)
{
	// Declare a hash table for storing the word counts
	std::map<std::string, int> wordMap;

	// Declare a stream for the text file
	std::ifstream inFile;

	// Declare a string for the words in the text 
	std::string words;

	// Attempt to open the file
	inFile.open(asciiFilename);

	// Check that the file was opened successfully
	if (!inFile)
	{
		std::cout << "Error: Unable to load the file " << asciiFilename << "." << std::endl;
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
			// Make the word suitable for the word map
			*word = PrepareWord(*word);

			// Check that the word has at least five characters
			if (word->length() <= 4)
				continue;

			// Place the word in the hash table
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

	// Declare a string for the filename
	std::string asciiFilename;

	// Check that the correct number of arguments were given
	if (argc == 2)
	{
		asciiFilename = argv[1];
	}
	else
	{
		std::cout << "Error: Incorrect number of arguments given. Expected 2." << std::endl;
		exit(1);
	}

	// Pass the filename argument to the word count function
	wordMap = CountWords(asciiFilename);

	SaveWordCountToFile(wordMap);

}
