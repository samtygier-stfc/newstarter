#include <iostream>
#include <fstream>
#include <string>
#include <map>

// define map type which stores values in descending order
typedef std::map<std::string, int, greater <int> > maptype

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

/** Loads a .txt file, checking for success. Subsequently reads the file
 *	storing all unique words and their numbers of occurrence
 *
 * @param filename: name of the input file to read
 * @param inputmap: map which will store all unique words and instances
 * @param char_min: default variable to limit the length of words
 * @return 
 *
 */

/* return type */ readFile(const std::string& filename, maptype& inputmap, std::size_t char_min = 4) {
	// attempt to open file
	ifstream inFile;
	// could use regex here...
	inFile.open(filename + ".txt");
	if (!inFile) {
		std::cerr << "Unable to open requested file: " << filename << "\n";
		std::exit(1); // terminate with error -------------------- maybe use try/except?
	}
	else {
		// read contents to map
		std::string word;
		while (inFile >> word) {
			// lower limit number of chars
			strlen(word.c_str()) > char_min ? ++inputmap[word];
		}
	}
	return True
}

/** Writes the results contained within the map to file
 *
 * @param outputmap: map to write to file
 * @param 
 * @param 
 * @return 
 *
 */

/* return type */ writeFile(maptype& outputmap) {
	std::ofstream outfile("word_counts.txt");
	outfile << "Word\tUsage\n";
	for (maptype::const_iterator it = outputmap.begin();
		it != outputmap.end(); ++it) {
		outfile << it->first << ' ' << it->second << "\n";
	}
}

// make case and punctuation insensitive
// clean .,?'"!(): (use backslash for ")
// edit header file