
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


void toLower(string &stringName) {
	/* Function accepts a string and modifies string
	by making it lowercase and returns nothing
	*/
	string PlaceHolderString{  };
	for (char Letter : stringName) 
		PlaceHolderString += tolower(Letter);
	
	stringName = PlaceHolderString;

}


void removePunctuation(string &stringName) {
	/* Function accepts a string a modifies string by
	removing any occurence of ".,?'"!():" within word 
	and returns nothing
	*/
	for (int i = 0; i < stringName.size();) {
		char a{ stringName[i] };
		if (stringName[i] == '"'|| stringName[i] == '!' || stringName[i] == '(' 
			|| stringName[i] == ')' || stringName[i] == ':' || stringName[i] == '\'' 
			|| stringName[i] == ',' || stringName[i] == '?' || stringName[i] == '.') 
		{
			stringName.erase(i, 1);
			i--;
		}
		i++;
	}
}


string getWord(ifstream &stream) {
	/* Function accept an input stream object and return a string from 
	input stream by reading stream 1 character at a time and concatenating
	it to a string until a space ,newline or '-'  character.
	*/
	string OutputString{};
	char InputCharacter{};

	while (true) {
		stream.get(InputCharacter);
		if (InputCharacter == '-' || InputCharacter == ' ' || InputCharacter == '\n'||stream.eof())
			break;
		OutputString += InputCharacter;
	}
	return OutputString;
}


int findString(const string &SearchString, const vector <string> &SearchList) {
	/*Function accept a string and vector of strings and searches for given string in 
	vector returns index at which it is found or -1 if it does not exist 
	in vector
	*/
	for (int Index = 0; Index < SearchList.size(); Index++) {
		if (SearchList[Index] == SearchString) {
			return Index;
		}
	}
	return -1;
}


int findInt(const int &SearchInteger,const vector <int> &SearchList) {
	/*Function accept an integer and vector of integers and searches for given integer in
	vector returns index at which it is found or -1 if it does not exist
	in vector
	*/
	for (int Index = 0; Index < SearchList.size(); Index++) {
		if (SearchList[Index] == SearchInteger) {
			return Index;
		}
	}
	return -1;
}


int main() { 
	/*This block of code declares all vectors used 
	and gets input from user so a to open 
	input file
	*/
	vector <string> VectorOfWords{};
	vector <int> VectorOfCounts{};
	vector <int> VectorOfOrderToRead{};
	char FilePathToInput [100];
	cout << "Please input a file path to input file :";
	cin.getline(FilePathToInput,100);
	ifstream FileToRead;
	FileToRead.open(FilePathToInput);
	
	if (!FileToRead) {
		/* This if block checks if file was opened correctly 
		and if it was not program is terminated
		*/
		cout << "File could not be opened" << endl;
		cout << "Ensure that file path is valid" << endl;
		return 1;
	}
	while(!FileToRead.eof()) {
		/* This while block reads input file and adds formatted words to
		VectorOfWords until the end of file has been reached. This block 
		has an if , else if block that determines whether word is more than 
		4 letters and already exists in VectorOfWords. if it does it increments 
		the count in VectorOfCounts otherwise it is added to VectorOfWords
		*/
		string HolderString{ };
		HolderString = getWord(FileToRead);
		toLower(HolderString);
		removePunctuation(HolderString);
		int location = findString(HolderString, VectorOfWords);
		if (HolderString.size() > 4 && location == -1) {
			VectorOfWords.push_back(HolderString);
			VectorOfCounts.push_back(1);
		}
		else {
			if (HolderString.size() > 4 && location != -1)
			{
				VectorOfCounts.at(location) += 1;
		}
		}
	}
	FileToRead.close();

	for (int i = 0; i < VectorOfWords.size(); i++) {
		/*This for block produces a vector called VectorOfOrderToRead which contains 
		in order integers that correspond to the indexes in which VectorOfWords and
		VectorOfCounts should be read in order to obtain list in descending order of count
		*/
		int MaxCount { 0 };
		int Index{ 0};
		for (int j = 0; j < VectorOfCounts.size(); j++) {

			if ( VectorOfCounts[j] > MaxCount && findInt(j,VectorOfOrderToRead)== -1) {
				Index = j;
				MaxCount = VectorOfCounts[j];
			}
		}
		VectorOfOrderToRead.push_back(Index);
	}

	cout << "First 8 words and count of each word" << endl ;
	for (int i = 0; i < 8; i++) {
		cout << left << setw(15) << VectorOfWords[VectorOfOrderToRead[i]];
		cout<< setw(15) << VectorOfCounts[VectorOfOrderToRead[i]] <<endl;
	}
	/*This block asks user to give a filepath to output file
	and outputs the word and counts in descending order of c
	counts
	*/
	cout << "Please input a file path to output file :";
	char FilePathToOutput[100];
	cin.getline(FilePathToOutput,100);
	ofstream FileToWrite;
	FileToWrite.open(FilePathToOutput, ios::app);
	if (!FileToWrite) {
		/* This if block checks if file was opened correctly
		and if it was not program is terminated
		*/
		cout << "File could not be opened" << endl;
		cout << "Ensure that file path is valid" << endl;
		return 1;
	}
	FileToWrite << left << setw(15) << "Word";
	FileToWrite << setw(15) << "Count" << endl;
	for (int i = 0; i < VectorOfWords.size(); i++) {

		FileToWrite << left << setw(15) << VectorOfWords[VectorOfOrderToRead[i]];
		FileToWrite << setw(15) << VectorOfCounts[VectorOfOrderToRead[i]] << endl;
	}
	cout << "Data appended to file" << endl;

	FileToWrite.close();
}
