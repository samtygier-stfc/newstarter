#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>


void ReadFile(std::string asciiFilename)
{
	// Declare a hash table for storing the word counts
	std::map<std::string, int> wordMap;

	// Declare a stream for the text file
	std::ifstream inFile;

	// Declare a string for the words in the text 
	std::string word;
	
	// Declare a string of punctuation characters
	std::string unwantedChars = ".,?'\"!():;";

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
		inFile >> word;

		// Remove the unwanted characters from the string
		for (int i = 0; i < unwantedChars.length(); i++)
		{
			word.erase(std::remove(word.begin(), word.end(), unwantedChars[i]), word.end());
		}

		// Check that the word has at least five characters
		if (word.length() <= 4)
			continue;

		// Convert the word to lower case
		for (unsigned int i = 0; i < word.length(); ++i) 
		{
			word[i] = std::tolower(word[i]);
		}

		// Place the word in the hash table
		wordMap[word]++;
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
