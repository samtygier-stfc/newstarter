/**
 * Read text file and count instances of words with >= 4 letters, then save the information to a file.
 *
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>

 /** Compare number of instances of two words.
  * @param wordA
  * @param wordB
  * @return True if wordA has higher count than wordB
 */
bool compareWordCount(const std::pair<std::string, int>& wordA, const std::pair<std::string, int>& wordB)
{
  return wordA.second > wordB.second;
}

/** Write the words and their counts to file.
 *
 * @param wordCounts
 * @param fileName
 * @return False if the file doesn't open.
*/
bool writeWordCountsToFile(std::vector<std::pair<std::string, int>>& wordCounts, const std::string& fileName)
{
  std::ofstream outputFile(fileName);

  if (!outputFile)
  {
    return false;
  }

  //Something is wrong if there aren't any words.
  if (wordCounts.size() == 0)
  {
    return false;
  }

  //Find length of longest word so that we can add padding to align everything nicely.
  int longestWordLength = 0;
  for (auto wordCount : wordCounts)
  {
    if (wordCount.first.length() > longestWordLength)
    {
      longestWordLength = static_cast<int>(wordCount.first.length());
    }
  }

  //Find number of digits in the count of the most frequent word. In the very unlikely case
  //that the longest word has the highest count, we want everthing to still be nicely aligned,
  //Use the test file Holmes_withLotsOfLongestWord.txt to check this.
  //The word counts are sorted, so the first will be the longest.
  int maxDigits = 0;
  if (wordCounts[0].second > 0)
  {
    maxDigits = static_cast<int>(log10(static_cast<double>(wordCounts[0].second)) + 1);
  }

  //If the number of digits in the biggest count is less than 5, just use 5 so that the
  //count column lines up with the "usage" column header.
  maxDigits = std::max(5, maxDigits);

  //Separation between the headers. The 4 is subtracted because that's the length of the first header ("Word").
  int headerPadding = 1 + longestWordLength + maxDigits - 4;
  outputFile << "Word" << std::setw(headerPadding) << "Usage" << std::endl << std::endl;

  for (auto wordCount : wordCounts)
  {
    //Calcluate a padding size so that the columns are aligned nicely.
    //Add one so that there's always a gap between the longest word and the count.
    int paddingSize = 1 + longestWordLength + maxDigits - static_cast<int>(wordCount.first.length());
    outputFile << wordCount.first << std::setw(paddingSize) << wordCount.second << std::endl;
  }

  outputFile.close();

  return true;
}

/** Read text file and count instances of words with >= 4 letters, then save the information to a file.
 * @param argc
 * @param argv - user must supply an input file name, and optionally an output file name.
 * @return
*/
int main(int argc, char* argv[])
{
  //Check that there are either 2 or 3 arguments. User must specify an input file name,
  //and optionally they can specify and output file name.
  if (argc < 2 || argc > 3)
  {
    std::cout << "Please provide arguments for input file (and optionally output file)." << std::endl;
    return 1;
  }

  //Input file is the first argument.
  std::string inputFileName = argv[1];

  //If there was an output file name specified, use that. Otherwise default to output.txt.
  std::string outputFileName = "output.txt";
  if (argc == 3)
  {
    outputFileName = argv[2];
  }

  std::ifstream inputFile(inputFileName);

  if (!inputFile)
  {
    std::cout << "Unable to open file " << inputFileName << std::endl;
    return 1;
  }

  //Line of text from input source.
  std::string line;

  std::map<std::string, int> wordCounts;

  //Read file one line at a time, or until we reach a hyphen.
  while (std::getline(inputFile, line, '-'))
  {
    std::istringstream wordsInLine(line);

    std::string word;

    //Loop over words in the line, using whitespace as delimiter.
    while (wordsInLine >> word)
    {
      //Only consider words > 3 characters long.
      if (word.length() < 4)
      {
        continue;
      }
      //Remove all punctuation characters:
      //.,?'"!():
      //Need to escape several of them because they are special pattern
      //characters in regex expressions.
      std::regex specialCharacters("\\.|,|\\?|'|\"|!|\\(|\\)|:");
      std::string newWord = std::regex_replace(word, specialCharacters, "");

      //Check again for the length of the word because it will be shorter if punctuation was removed.
      if (newWord.length() < 4)
      {
        continue;
      }

      //Convert word to lower case.
      std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);

      //Increment the count of the word.
      wordCounts[newWord]++;
    }
  }

  //If there are no words, don't do anything else.
  if (wordCounts.size() == 0)
  {
    std::cout << "No valid words found in file " << inputFileName << std::endl;
    return 1;
  }

  //Container to store the word counts sorted by count.
  std::vector<std::pair<std::string, int>> sortedWordCounts;

  std::copy(wordCounts.begin(), wordCounts.end(), std::back_inserter(sortedWordCounts));

  std::sort(sortedWordCounts.begin(), sortedWordCounts.end(), compareWordCount);

  //Save the sorted words to the output file.
  if (!writeWordCountsToFile(sortedWordCounts, outputFileName))
  {
    std::cout << "Error encountered while writing to file " << outputFileName << std::endl;
    return 1;
  }
  else
  {
    std::cout << "Output successfully written to file " << outputFileName << std::endl;
  }

  return 0;

}