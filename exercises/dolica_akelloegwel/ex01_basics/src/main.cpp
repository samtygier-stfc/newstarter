#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>


void ReadFile(std::string asciiFilename)
{
	std::map<std::string, int> wordMap;
	std::ifstream inFile;
	std::string word;

	inFile.open(asciiFilename);

	if (!inFile)
	{
		std::cout << "Error: Unable to load the file " << asciiFilename << "." << std::endl;
		exit(1);
	}

	while (!inFile.eof())
	{
		inFile >> word;

		if (word.length() <= 4)
			continue;

		for (unsigned int i = 0; i < word.length(); ++i) 
		{
			word[i] = std::tolower(word[i]);
		}

		wordMap[word]++;
	}

	inFile.close();

	for (auto it = wordMap.cbegin(); it != wordMap.cend(); ++it)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}

}
int main(int argc, char *argv[])
{
	
	std::string asciiFilename;

	if (argc == 2)
	{
		asciiFilename = argv[1];
	}
	else
	{
		std::cout << "Error: Incorrect number of arguments given. Expected 2." << std::endl;
		exit(1);
	}

	ReadFile(asciiFilename);

	

}
