#include <string>
#include <iostream>
#include <fstream>
/**
 * Skeleton main routine
 */

void ReadFile(std::string ascii_filename)
{
	std::ifstream inFile;
	std::string line;

	inFile.open(ascii_filename);

	if (!inFile)
	{
		std::cout << "Error: Unable to load the file " << ascii_filename << "." << std::endl;
		exit(1);
	}

	while (!inFile.eof())
	{
		inFile >> line;
		std::cout << line;
	}

	inFile.close();

}
int main(int argc, char *argv[])
{
	std::string ascii_filename;

	if (argc == 2)
	{
		ascii_filename = argv[1];
	}
	else
	{
		std::cout << "Error: Incorrect number of arguments given. Expected 2." << std::endl;
		exit(1);
	}

	ReadFile(ascii_filename);

}
