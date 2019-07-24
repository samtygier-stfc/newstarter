#include "main.h"

int main(int argc, char **argv) {
	// prompt user for filename
	std::cout << "Please enter the name of a file you wish to read: ";
	std::string file_name;
	std::cin >> file_name;

	// create map
	maptype wordCounts;

	// read file
	readFile(file_name, wordCounts);

	// write file
	writeFile(wordCounts);

	// report to user
	std::cout << "Number of distinct words: " << wordCounts.size() << "\n"
			  << "Open output file for more detail\n";
}

/** Takes a string from which to clean specified characters from
 *	appearing after words
 *
 * @param words: string to be cleaned
 * @return 
 *
 */

void cleanWords(std::string& word) {
	std::regex string_regex("[^\\.,:;!?()\"-]+");
	auto string_begin = std::sregex_iterator(word.begin(), word.end(), string_regex);
	auto string_end = std::sregex_iterator();

	for (std::sregex_iterator it = string_begin; it != string_end; ++it)
		std::remove_copy(word.begin(), word.end(), std::back_inserter(cleaned), string_regex);
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

void readFile(const std::string& filename, maptype& inputmap, std::size_t char_min = 4) {
	// attempt to open file
	std::ifstream inFile;
	// could use regex here...
	inFile.open(filename + ".txt");
	if (!inFile) {
		std::cerr << "Unable to open requested file: " << filename << '\n';
		std::exit(1); // terminate with error ------------------------------------ maybe use try/except?
	}
	else {
		// read contents to map
		std::string word;
		while (inFile >> word) {
			// lower limit number of chars
			if (strlen(word.c_str()) > char_min) {
				cleanWords(word);
				++inputmap[word];
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

void writeFile(maptype& outputmap) {
	std::ofstream outfile("word_counts.txt");
	outfile << "Word\tUsage\n";
	for (maptype::const_iterator it = outputmap.begin();
		it != outputmap.end(); ++it) {
		outfile << it->first << '\t' << it->second << '\n';
	}
}

// make case and punctuation insensitive
// clean .,?'"!(): (use backslash for ")
// treat hypenated words as a different word
// presereve apostrophe inside word
// edit header file
// writeFile error message check
// research transform and tolower