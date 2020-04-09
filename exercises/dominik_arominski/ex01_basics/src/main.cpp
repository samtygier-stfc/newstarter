#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string RemovePunctuation(std::string word) {
  const char punctuation[] = {'.', ',', '?', '!', '"', '\'', ')', '('};
  for (auto punc : punctuation) {
    if(word.find(punc) < 100) {
      word = word.substr(0, word.find(punc)) +  word.substr(word.find(punc)+1, word.size());
    }
  }
  return word;
}

std::vector<std::string> RemoveHyphenation(std::string const word) {
  std::string const word1 = word.substr(0, word.find("-"));
  std::string const word2 = word.substr(word.find("-")+1, word.size());
  return {word1, word2}; 
}

int main(int argn, char **argc)
{
  if (argn < 2) {
    throw std::runtime_error("File name not provided.");
  }
  else if (argn > 2) {
    throw std::runtime_error("More than one input file has been provided. Please provide only one file name.");
  }
  
  std::fstream inputFile;
  inputFile.open(argc[1], std::fstream::in);
  if (!inputFile) {
    throw std::runtime_error("Could not open input file.");
  }

  std::map<std::string, int> wordMap;
  std::string word;
  while(inputFile >> word) {
    if (word.size() < 4 ) {
      continue;
    }
    word = RemovePunctuation(word);
    if (word.find("-") < 100) {
      auto newWords = RemoveHyphenation(word);
      for (auto newWord : newWords) {
	if (newWord.size() < 4)
	  continue;
	std::transform(newWord.begin(), newWord.end(), newWord.begin(), [](const unsigned char c){ return std::tolower(c); });
	wordMap[newWord] += 1;
      }
    }
    else {
      std::transform(word.begin(), word.end(), word.begin(), [](const unsigned char c){ return std::tolower(c); });
      wordMap[word] += 1;
    }
  }
    
  std::vector<std::pair<std::string, int>> wordVector;
  for (auto itr = wordMap.begin(); itr != wordMap.end(); ++itr)
    wordVector.push_back(*itr);
  
  sort(wordVector.begin(), wordVector.end(), [=](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
	 return a.second > b.second;
    });

  std::fstream outputFile;
  outputFile.open("results.dat", std::fstream::out);
  if (!outputFile) {
    throw std::runtime_error("Could not open output file.");
  }
  outputFile << "Word\tUsage" << std::endl;
  
  for (auto elem : wordVector) {
    outputFile << elem.first << "\t" << elem.second << std::endl;
  }
  
  inputFile.close();
  outputFile.close();
  return 0;
}
