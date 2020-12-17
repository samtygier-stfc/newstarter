#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <sstream>

std::vector<std::string> analyseLine(std::string line)
{
  // Remove punctuation that accompanies a space
  std::vector<char> punctuation = {'?','.',',', '\'', '"', '(', ')', '!', ':', ';'};
  for (char mark : punctuation)
  {
    line.erase(std::remove(line.begin(), line.end(),mark), line.end());
  }

  // Hyphens don't accompany spaces so replace with a space and split words
  std::replace( line.begin(), line.end(), '-', ' ');

  // force all letters to case lower
  std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){ return std::tolower(c);});

  std::vector<std::string> words;

  std::stringstream lineOfText(line);
  std::string word;
  while (lineOfText >> word) {
    if (word.size() > 4)
      words.push_back(word);
  }

  return words;
}


// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/

// Convert map into vector of pairs, sorted by value of counts
std::vector<std::pair<std::string, int> > sortByValue(const std::map<std::string, int>& M) 
{
  // Declare vector of pairs 
  std::vector<std::pair<std::string, int> > A; 

  // Copy key-value pair from Map to vector of pairs 
  for (auto& it : M) { A.push_back(it); } 

  // Sort using comparator function 
  std::sort(A.begin(), A.end(), 
    [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
    { return a.second > b.second; }); 

  return A;
} 

int main()
{
  // Ask for input text to WordCount
  std::cout << "Welcome to the WordCounter... \n\n";
  std::cout << "Please enter the filename to analysed, e.g. MyFile.txt \n\n";
  std::string filename;
  std::cin >> filename;

  // Append .txt if not already contained in filename
  size_t filenameLength = filename.length();
  if (filenameLength < 4 || filename.substr(filenameLength-4,filenameLength) != ".txt")
  {
    filename += ".txt";
  }

  // Read in each line, Analyse and adds counts to the CounterMap
  std::fstream fs{ filename };
  std::string rawLine;
  std::map<std::string, int> counterMap;
  while (fs)
  {
    std::getline(fs, rawLine);
    std::vector<std::string> wordsAnalysed = analyseLine(rawLine);
    // Update counterMap
    for (auto& word : wordsAnalysed)
    {
      counterMap[word]++ ;
    }
  }

  // Convert map into vector of pairs, sorted by value of counts
  auto counterVec = sortByValue(counterMap);

  // Write out results to file
  std::string filenameOut = "Stats_WC_" + filename;
  std::fstream fs_out{filenameOut, std::ios::out};
  fs_out << "\n\nWords" << std::setw(34) << "Count\n#####" << std::setw(30) << "#####\n\n";

  int isEmpty = 0;
  try{
    if (counterVec.size() == 0)
    { 
      isEmpty = 1;
      throw filename;
    }
  }
  catch (std::string x)
  {
    std::cout << "\n ***The input file " << x << " could not be analysed by WordCount.*** \
    \nPlease check you have the correct name for the input text file, e.g. MyFile.txt.\n\n";
  }

  if (isEmpty == 0)
  {
    for (auto el : counterVec)
    {
      size_t wordLength = el.first.length();
      fs_out << el.first << std::string(30-wordLength, ' ') << el.second << "\n";
    }
    std::cout << "WordCount results are saved to " << filenameOut << "\n";
  }
}
