#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <sstream>

std::vector<std::string> AnalyseLine(std::string line)
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

std::map<std::string, int> UpdateMap(const std::vector<std::string> &words, std::map<std::string,int>& Counter)
{
  for (auto& word : words)
  {
    // if word already a member, increment its count by 1
    Counter[word]++ ;
  }
  return Counter;
}

// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/
bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
  return a.second > b.second;
}

// Convert map into vector of pairs, sorted by value of counts
std::vector<std::pair<std::string, int> > sort_by_value(const std::map<std::string, int>& M) 
{
  // Declare vector of pairs 
  std::vector<std::pair<std::string, int> > A; 

  // Copy key-value pair from Map to vector of pairs 
  for (auto& it : M) { A.push_back(it); } 

  // Sort using comparator function 
  sort(A.begin(), A.end(), cmp); 

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
  size_t filename_length = filename.length();
  if (filename_length < 4 || filename.substr(filename_length-4,filename_length) != ".txt")
  {
    filename += ".txt";
  }

  // Read in each line, Analyse and adds counts to the CounterMap
  std::fstream fs{ filename };
  std::string raw_line;
  std::map<std::string, int> CounterMap;
  while (fs)
  {
    std::getline(fs, raw_line);
    std::vector<std::string> words_analysed = AnalyseLine(raw_line);
    CounterMap = UpdateMap(words_analysed, CounterMap);
  }

  // Convert map into vector of pairs, sorted by value of counts
  auto CounterVec = sort_by_value(CounterMap);

  // Write out results to file
  std::string filename_out = "Stats_WC_" + filename;
  std::fstream fs_out{filename_out, std::ios::out};
  fs_out << "\n\nWords" << std::setw(34) << "Count\n#####" << std::setw(30) << "#####\n\n";

  int is_empty = 0;
  try{
    if (CounterVec.size() == 0)
    { 
      is_empty = 1;
      throw filename;
    }
  }
  catch (std::string x)
  {
    std::cout << "\n ***The input file " << x << " could not be analysed by WordCount.*** \
    \nPlease check you have the correct name for the input text file, e.g. MyFile.txt.\n\n";
  }

  if (is_empty == 0)
  {
    for (auto el : CounterVec)
    {
      size_t word_length = el.first.length();
      fs_out << el.first << std::string(30-word_length, ' ') << el.second << "\n";
    }
    std::cout << "WordCount results are saved to " << filename_out << "\n";
  }
}
