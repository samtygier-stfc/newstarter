#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

/**implements a variation of counting  sort by modifying vector in place.
  *
  *@param vectorOfPairs a vector containing  pairs of integers and strings respectively
  *@returns nothing
  *
*/

void countingSort(std::vector<std::pair< int ,std::string > > &vectorOfPairs) {
  int maxCount{0};
  
  for (auto& pair : vectorOfPairs) {
    if (pair.first > maxCount) {
      maxCount = pair.first;
    }
  }
  std::vector <std::vector <int>> vectorForSort;
  for (int i = 0; i < maxCount; i++) {
    std::vector <int> emptyVector;
    vectorForSort.emplace_back(emptyVector);
  }

  for (int i = 0; i < vectorOfPairs.size(); i++) {
    int index = vectorOfPairs[i].first - 1;
    vectorForSort[index].emplace_back(i);
  }
  std::vector <std::pair<int, std::string>> sortedVector;
  for (int i = int(vectorForSort.size()) - 1; i >= 0; i--) {
    for (auto& order : vectorForSort[i]) {
      sortedVector.emplace_back(vectorOfPairs[order]);
    }
  }
  vectorOfPairs = sortedVector;
}

/**returns a formatted word from input file
  *
  *@param stream the ifstream object to read from
  *returns a formatted string
  */
std::string getWord(std::ifstream& stream) {
  
  std::string outputString;
  char inputCharacter;

  while (true) {
    stream.get(inputCharacter);
    if (inputCharacter == '-' || inputCharacter == ' ' || inputCharacter == '\n' || stream.eof())
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
  

  char filePathToInput[150];
  std::cout << "Please input a file path to input file :";
  std::cin.getline(filePathToInput, 150);
  std::ifstream fileToRead;
  fileToRead.open(filePathToInput);
  std::vector <std::pair<int, std::string>> vectorOfCountsAndWords;

  if (!fileToRead) {
    /* This if block checks if file was opened correctly
    and if not program is terminated
    */
    std::cout << "File could not be opened" << std::endl;
    std::cout << "Ensure that file path is valid" << std::endl;
  }
  std::string holderString;
  auto myPredicator = [&holderString](std::pair<int, std::string>& pairOfCountAndWord)
  {
    return (pairOfCountAndWord.second == holderString);
  };

  while (!fileToRead.eof()) {
    /* This while block reads input file and adds formatted words to
    VectorOfWords until the end of file has been reached. This block
    has an if , else if block that determines whether word is more than
    4 letters and already exists in VectorOfWords. if it does it increments
    the count in VectorOfCounts otherwise it is added to VectorOfWords
    */
    
    holderString = getWord(fileToRead);
    
    if (holderString.size() > 4){
      auto location = std::find_if(vectorOfCountsAndWords.begin(), vectorOfCountsAndWords.end(), myPredicator);
    if (location == vectorOfCountsAndWords.end()) {
      vectorOfCountsAndWords.emplace_back(1,holderString);
    }
    else {
        vectorOfCountsAndWords[std::distance(vectorOfCountsAndWords.begin(), location)].first += 1;
      }
    }
  }
  fileToRead.close();
  /*
  Counting sort method has been implemented that is faster than most std::sort 
  implementions.
  countingSort(vectorOfCountsAndWords);
  */
  std::sort(vectorOfCountsAndWords.rbegin(), vectorOfCountsAndWords.rend());
  /*Block of code displays first 8  words and count
  of words in sorted order
  */
  std::cout << "First 8 words and count of each word" << std::endl;
  for (int i = 0; i < 8; i++) {
    std::cout << std::left << std::setw(15) << vectorOfCountsAndWords[i].second;
    std::cout << std::setw(15) << vectorOfCountsAndWords[i].first << std::endl;
  } 
  /*This block asks user to give a filepath to output file
  and outputs the word and counts in descending order of 
  counts into file*/

  std::cout << "Please input a file path to output file :";
  char filePathToOutput[150];
  std::cin.getline(filePathToOutput, 150);
  std::ofstream fileToWrite;
  fileToWrite.open(filePathToOutput, std::ios::app);
  if (!fileToWrite) {
    /* This if block checks if file was opened correctly
    and if not program is terminated
    */
    std::cout << "File could not be opened" << std::endl;
    std::cout << "Ensure that file path is valid" << std::endl;
    return 1;
  }
  fileToWrite << std::left << std::setw(15) << "Word";
  fileToWrite << std::setw(15) << "Count" << std::endl;
  for (int i = 0; i < vectorOfCountsAndWords.size(); i++) {

    fileToWrite << std::left << std::setw(15) << vectorOfCountsAndWords[i].second;
    fileToWrite << std::setw(15) << vectorOfCountsAndWords[i].first << std::endl;
  }
  std::cout << "Data appended to file" << std::endl;

  fileToWrite.close();

}

