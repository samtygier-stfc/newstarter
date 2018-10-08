#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>

std::vector<std::string> SplitWords(std::string compositeWord)
{
	std::vector<std::string> words;

	std::string twoDash = "--";
	std::string oneDash = "-";

	size_t twoDashLoc = compositeWord.find(twoDash);
	size_t oneDashLoc = compositeWord.find(oneDash);

	if (twoDashLoc != std::string::npos)
	{

	}
	else if (oneDashLoc != std::string::npos)
	{

	}
	else
	{
		// Place a single word in the vector
		words.push_back(compositeWord);
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

	// Return a word that is now suitable for the word map
	return rawWord;
}
void ReadFile(std::string asciiFilename)
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

		// Make the word suitable for the word map
		words = PrepareWord(words);

		// Check that the word has at least five characters
		if (words.length() <= 4)
			continue;

		// Place the word in the hash table
		wordMap[words]++;
	}

	// Close the file
	inFile.close();

	// Print the contents of the wordmap
	for (auto it = wordMap.cbegin(); it != wordMap.cend(); ++it)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}

}
int main(int argc, char *argv[])
{
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
	ReadFile(asciiFilename);

}
