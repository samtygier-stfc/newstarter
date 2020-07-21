
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>



std :: string getWord(std :: ifstream &stream) {
	/* Function accept an input stream object and return a string from 
	input stream by reading stream 1 character at a time and concatenating
	it to a string until a space ,newline or '-'  character.
	*/
	std :: string outputString{};
	char inputCharacter{};

	while (true) {
		stream.get(inputCharacter);
		if (inputCharacter == '-' || inputCharacter == ' ' || inputCharacter == '\n'||stream.eof())
			break;
		if (inputCharacter == '"' || inputCharacter == '!' || inputCharacter == '('
			|| inputCharacter == ')' || inputCharacter == ':' || inputCharacter == '\''
			|| inputCharacter == ',' || inputCharacter == '?' || inputCharacter == '.')
			continue;

		outputString += tolower(inputCharacter);
	}
	return outputString;
}

int main() { 
	/*This block of code declares all vectors used 
	and gets input from user so a to open 
	input file
	*/
	std :: vector <std :: string> vectorOfWords{};
	std :: vector <int> vectorOfCounts{};
	std :: vector <int> vectorOfOrderToRead{};
	char filePathToInput [100];
	std :: cout << "Please input a file path to input file :";
	std :: cin.getline(filePathToInput,100);
	std :: ifstream fileToRead;
	fileToRead.open(filePathToInput);

	if (!fileToRead) {
		/* This if block checks if file was opened correctly
		and if it was not program is terminated
		*/
		std::cout << "File could not be opened" << std::endl;
		std::cout << "Ensure that file path is valid" << std::endl;
	}
	while(!fileToRead.eof()) {
		/* This while block reads input file and adds formatted words to
		VectorOfWords until the end of file has been reached. This block 
		has an if , else if block that determines whether word is more than 
		4 letters and already exists in VectorOfWords. if it does it increments 
		the count in VectorOfCounts otherwise it is added to VectorOfWords
		*/
		std :: string holderString{ };
		holderString = getWord(fileToRead);
		auto location = std::find(vectorOfWords.begin(), vectorOfWords.end(), holderString) ;
		if (holderString.size() > 4 && location == vectorOfWords.end()) {
			vectorOfWords.push_back(holderString);
			vectorOfCounts.push_back(1);
		}
		else {
			if (holderString.size() > 4 && location != vectorOfWords.end())
			{
				vectorOfCounts[std::distance(vectorOfWords.begin(), location)] += 1;
		}
		}
	}
	fileToRead.close();
	int maxCount{ 0 };
	/*Next Block of code implements a variation of counting
	sort  on vectorOfCounts to produce filled vectorOfOrderToRead*/
	for (auto& count : vectorOfCounts) {
		if (count > maxCount) {
			maxCount = count;
		}
	}
		std::vector <std::vector <int>> vectorForSort;
		for (int i = 0; i < maxCount; i++) {
			std::vector <int> emptyVector;
			vectorForSort.push_back(emptyVector);
		}
	
		for (int i = 0; i < vectorOfCounts.size(); i++) {
			int index = vectorOfCounts[i] - 1;
			vectorForSort[index].push_back(i);
		}
		for (int i = vectorForSort.size() - 1; i >= 0; i--) {
			for (auto& order : vectorForSort[i]) {
				vectorOfOrderToRead.push_back(order);
			}
		}
		/*Block of code displays first 8  words and count
		of words in sorted order
		*/
	std::cout << "First 8 words and count of each word" << std::endl ;
	for (int i = 0; i < 8; i++) {
		std::cout << std::left << std::setw(15) << vectorOfWords[vectorOfOrderToRead[i]];
		std::cout<< std::setw(15) << vectorOfCounts[vectorOfOrderToRead[i]] <<std::endl;
	}
	/*This block asks user to give a filepath to output file
	and outputs the word and counts in descending order of c
	counts*/
	
	std::cout << "Please input a file path to output file :";
	char filePathToOutput[100];
	std::cin.getline(filePathToOutput,100);
	std::ofstream fileToWrite;
	fileToWrite.open(filePathToOutput, std::ios::app);
	if (!fileToWrite) {
		/* This if block checks if file was opened correctly
		and if it was not program is terminated
		*/
		std::cout << "File could not be opened" << std::endl;
		std::cout << "Ensure that file path is valid" << std::endl;
		return 1;
	}
	fileToWrite << std::left << std::setw(15) << "Word";
	fileToWrite << std::setw(15) << "Count" << std::endl;
	for (int i = 0; i < vectorOfWords.size(); i++) {

		fileToWrite << std::left << std::setw(15) << vectorOfWords[vectorOfOrderToRead[i]];
		fileToWrite << std::setw(15) << vectorOfCounts[vectorOfOrderToRead[i]] << std::endl;
	}
	std::cout << "Data appended to file" << std::endl;

	fileToWrite.close();
	
}
