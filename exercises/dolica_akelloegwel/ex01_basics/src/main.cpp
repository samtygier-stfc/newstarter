#include <string>
#include <iostream>
#include <fstream>
#include <map>


void ReadFile(std::map<std::string, int> wordMap, std::string asciiFilename)
{
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
		wordMap[word]++;
		// std::cout << word << std::endl;
	}

	inFile.close();

}
int main(int argc, char *argv[])
{
	std::map<std::string, int> wordMap;
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

	ReadFile(wordMap,asciiFilename);

}
