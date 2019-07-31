#include "main.h"

int main(int argc, char **argv) {
	// prompt user for filename
	std::cout << "Please enter the name of a file you wish to read: ";
	std::string file_name;
	std::cin >> file_name;

	// create map
	MapType wordCounts;

	//declare file read boolean and unsigned max length
	bool read_bool;
	std::size_t max_len = 0;

	// read file
	try {
		read_bool = readFile(file_name, wordCounts, max_len);
	} catch (const char* msg) {
		std::cerr << msg << std::endl;
		read_bool = false;
	}

	//define lambda for comparison logic
	Comparator compFunctor =
		[](const Pair& elem1, const Pair& elem2) { return elem1.second > elem2.second; };

	// declare vector
	std::vector<Pair> ordered_vector;

	// order words
	orderWords(wordCounts, ordered_vector, compFunctor);

	// write file
	try {
		writeFile(ordered_vector, max_len, read_bool);
	} catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
}

/** Alters string to lower case
 *
 * @param word: string to be altered
 * @return word: string with all capitals lowered
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
 * @param word: string to be cleaned
 * @param cleaned_words: empty vector to store cleaned strings
 * @return void
 *
 */

void cleanWord(std::string& word, std::vector<std::string>& cleaned_words) {
	static const std::regex string_regex("(\\B'\b|\b'\\B)|([\\.,:;!?()\"-]+)");
	auto first = std::sregex_token_iterator(word.begin(), word.end(), string_regex, -1);
	std::copy(first, std::sregex_token_iterator(), std::back_inserter(cleaned_words));
}

/** Loads a .txt file, checking for success. Subsequently reads the file
 *	storing all unique words and their numbers of occurrence
 *
 * @param filename: name of the input file to read
 * @param inputmap: map which will store all unique words and instances
 * @param char_min: default variable to limit the length of words
 * @return bool: check for read success
 *
 */

bool readFile(const std::string& filename, MapType& inputmap, std::size_t& max_len, const std::size_t char_min) {
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
			std::string lowered = str_tolower(word);
			cleanWord(lowered, cleaned_words);
			for (auto it = cleaned_words.begin(); it != cleaned_words.end(); ++it) {
				if ((*it).size() > char_min) {
					++inputmap[*it];
					if ((*it).size() > max_len) {
						max_len = (*it).size();
					}
				}
			}
		}
		return true;
	}
}

/** Orders unique words in non-increasing order
 *
 * @param cleanedMap: map of cleaned words
 * @param outputVector: vector of pairs to stored ordered words
 * @param cmp: lambda function comparator
 * @return void
 *
 */

void orderWords(const MapType& cleanedMap, std::vector<Pair>& outputVector, const Comparator& cmp) {
	outputVector.reserve(cleanedMap.size());
	std::copy(cleanedMap.begin(), cleanedMap.end(), std::back_inserter(outputVector));
	std::sort(outputVector.begin(), outputVector.end(), cmp);
}

/** Determines whitespace formatting of output file
 *
 * @param str_1: lhs string
 * @param max_len: maximun length of strings
 * @return ws: string of appropriate number of white spaces
 *
 */

const std::string formatWhitespace(const std::string& str_1, const std::size_t& max_len) {
	std::string ws(max_len - str_1.length(), ' ');
	return ws;
}

/** Writes the results extracted from the map, into vector of pairs, to file
 *
 * @param orderedPair: ordered vector to write to file
 * @param max_len: maximun length of strings
 * @param read_bool: boolean to check file was read successfully
 * @return void
 *
 */

const void writeFile(const std::vector<Pair>& orderedPair, const std::size_t& max_len, bool& read_bool) {
	if (!read_bool) {
		throw "Unable to write file";
	}
	else {
		std::ofstream outfile("word_counts.txt");
		std::string header_1 = "Word", header_2 = "Usage";
		outfile << header_1 << formatWhitespace(header_1, max_len) << header_2 << "\n\n";
		for (auto it = orderedPair.begin();
			it != orderedPair.end(); ++it) {
			outfile << it->first << formatWhitespace(it->first, max_len) << it->second << '\n';
		}
	}
}

// implementation is slow :(