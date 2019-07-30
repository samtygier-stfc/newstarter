#include "main.h"

int main(int argc, char **argv) {
	// prompt user for filename
	std::cout << "Please enter the name of a file you wish to read: ";
	std::string file_name;
	std::cin >> file_name;

	// create map
	MapType wordCounts;

	// read file
	try {
		readFile(file_name, wordCounts);
	} catch (const char* msg) {
		std::cerr << msg << std::endl;
	}

	//define lambda for comparison logic
	Comparator compFunctor =
		[](const pair& elem1, const pair& elem2) { return elem1.second > elem2.second; };

	// declare vector
	std::vector<pair> orderedVector;

	// order words
	orderWords(wordCounts, orderedVector, compFunctor);

	// write file
	writeFile(orderedVector);

	// report to user
	std::cout << "Number of distinct words: " << orderedVector.size() << "\n"
			  << "Open output file for more detail\n";
}

/** Loads a .txt file, checking for success. Subsequently reads the file
 *	storing all unique words and their numbers of occurrence
 *
 * @param filename: name of the input file to read
 * @param inputmap: map which will store all unique words and instances
 * @param char_min: default variable to limit the length of words
 * @return
 *
 */

std::string str_tolower(std::string& word) {
	std::transform(word.begin(), word.end(), word.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return word;
}

/** Takes a string from which to clean specified characters from
 *	appearing after words
 *
 * @param words: string to be cleaned
 * @return 
 *
 */

void cleanWord(std::string& word, std::vector<std::string>& cleaned_words) {
	static const std::regex string_regex("(\B'\b|\b'\B)|([\\.,:;!?()\"-]+)");
	auto first = std::sregex_token_iterator(word.begin(), word.end(), string_regex, -1);
	std::copy(first, std::sregex_token_iterator(), std::back_inserter(cleaned_words));
}

/** Loads a .txt file, checking for success. Subsequently reads the file
 *	storing all unique words and their numbers of occurrence
 *
 * @param filename: name of the input file to read
 * @param inputmap: map which will store all unique words and instances
 * @param char_min: default variable to limit the length of words
 * @return 
 *
 */

void readFile(const std::string& filename, MapType& inputmap, const std::size_t char_min) {
	// attempt to open file
	std::ifstream inFile;
	inFile.open(filename + ".txt");
	if (!inFile) {
		throw "Unable to open requested file";
	}
	else {
		// read contents to map
		std::string word;
		while (inFile >> word) {
			// clean words
			std::vector<std::string> cleaned_words;
			cleanWord(str_tolower(word), cleaned_words);
			for(auto it = cleaned_words.begin(); it != cleaned_words.end(); ++it) {
				if ((*it).size() > char_min) {
					++inputmap[*it];
				}
			}
		}
	}
}

/** Writes the results contained within the map to file
 *
 * @param outputmap: map to write to file
 * @param
 * @param
 * @return
 *
 */

void orderWords(const MapType& cleanedMap, std::vector<pair>& outputVector, Comparator& cmp) {
	outputVector.reserve(cleanedMap.size());
	std:copy(cleanedMap.begin(), cleanedMap.end(), std::back_inserter(outputVector));
	std::sort(outputVector.begin(), outputVector.end(), cmp);
}

/** Writes the results contained within the map to file
 *
 * @param outputmap: map to write to file
 * @param 
 * @param 
 * @return 
 *
 */

void writeFile(const std::vector<pair>& outputVector) {
	std::ofstream outfile("word_counts.txt");
	outfile << "Word\tUsage\n\n";
	for (auto it = outputVector.begin();
		it != outputVector.end(); ++it) {
		outfile << it->first << '\t' << it->second << '\n';
	}
}

// create longest word whitespace
// const and auto
// return types?!?!?!?!?!?!