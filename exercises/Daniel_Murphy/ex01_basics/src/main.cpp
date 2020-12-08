#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class ReadFile
{
public:
	std::vector<string> AnalyseLine(string line);
	std::map<string, int> UpdateMap(std::vector<string> words);
};


std::vector<string> ReadFile::AnalyseLine(string line)
{
	std::vector<int> positions = {-1}; // holds positions of all spaces, include the start of the line

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

	// Find position of space
	int pos = static_cast<int>(line.find(" ",0));
	while(pos != static_cast<int>(string::npos))
	{
		positions.push_back(pos);
		pos = static_cast<int>(line.find(" ",pos+1));
	}
	positions.push_back(static_cast<int>(line.length())); // add the end of the line

	// Cut the line by the space positions into words
	std::vector<string> words;
	for (auto iter = positions.begin(); iter != positions.end()-1; iter++)
	{
		int length = *(iter+1) - ((*iter)+1); // word length = end - start
		// do not log spaces as words
		if (length > 4)	{	words.push_back(line.substr(((*iter)+1), length));	}
	}

	return words;
}

std::map<string, int> ReadFile::UpdateMap(std::vector<string> words)
{
	static std::map<string, int> Counter;
	for (string word : words)
	{
		auto member_check = Counter.find(word);
		// if word already a member, increment its count by 1
		if(member_check != Counter.end())

		{	Counter[word]++ ;	} 
		else // add word to map
		{	Counter[word] = 1;	}
	}
	return Counter;
}

// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/
bool cmp(std::pair<string, int>& a, std::pair<string, int>& b)
{
	return a.second > b.second;
}

// Convert map into vector of pairs, sorted by value of counts
std::vector<std::pair<string, int> > sort_by_value(std::map<string, int>& M) 
{
	// Declare vector of pairs 
	std::vector<std::pair<string, int> > A; 

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
	string filename;
	std::cin >> filename;

	// Append .txt if not already contained in filename
	size_t filename_length = filename.length();
	if (filename_length < 4 || filename.substr(filename_length-4,filename_length) != ".txt")
	{
		filename += ".txt";
	}

	// Read in each line, Analyse and adds counts to the CounterMap
	std::fstream fs{ filename };
	string raw_line;
	std::map<string, int> CounterMap;
	while (fs)
	{
		std::getline(fs, raw_line);
		ReadFile o;
		std::vector<string> words_analysed = o.AnalyseLine(raw_line);
		CounterMap = o.UpdateMap(words_analysed);
	}

	// Convert map into vector of pairs, sorted by value of counts
	auto CounterVec = sort_by_value(CounterMap);

	// Write out results to file
	string filename_out = "Stats_WC_" + filename;
	std::fstream fs_out{filename_out, std::ios::out};
	fs_out << "\n \nWords                       Count\n#####                       #####\n \n";

	int is_empty = 0;
	try{
		if (CounterVec.size() == 0)
		{ 
			is_empty = 1;
			throw filename;
		}
	}
	catch (string x)
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
