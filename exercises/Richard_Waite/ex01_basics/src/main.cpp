#include <iomanip> // setprecision
#include <ios>
#include <iostream> // cout, cin, endl
#include <string>
#include <vector> // vector
#include<algorithm> // sort, max
#include<stdexcept>
#include <list>
#include<cctype> // isspace isalnum - why not need to include
#include<numeric>
#include<map>
#include<fstream>

bool isHyphen(char c) {
	return c=='-';
}

bool notHyphen(char c) {
	return !isHyphen(c);
}

std::vector<std::string> hyphenSplit(const std::string& str) {
	/*
	Function to split a string by a delimiter char (e.g. space)
		 i     j
	Some-example-text
		 ^      ^
	*/

	std::vector<std::string> ret;
	typedef std::string::const_iterator iter;

	iter i = str.begin();

	while (i != str.end()) {

		i = find_if(i, str.end(), notHyphen);
		/*
		find_if applies the predicate to each valeue in range [iter_1, iter_2)
		stopping when an element yields TRUE
		*/

		// find end of next word
		iter j = find_if(i, str.end(), isHyphen);

		// copy the characters in range [i,j)
		if (i != str.end()) {
			ret.push_back(std::string(i, j));
			i = j;
		}
	}
	return ret;
}

// function to sort keys in map by value


int main(int argc, char** argv)
{
	std::string filename;
	if (argc == 2) {
		// second commandline argument is a filename
		filename = argv[1];
	}
	else {
		//throw error to tell user to pass filename
		throw std::domain_error("user must pass the executable a filename.");
	}

	// read file to istream-like thing
	std::ifstream infile(filename.c_str());

	// punctuation to accept
	static const std::string punctuation = ".,?'\"!():";

	std::string s;
	std::vector<std::string> substrs;
	const std::string::size_type minlen = 5;
	std::map<std::string, int> counters;

	// read each word in file
	while (infile >> s) {
		/*
		increment the int referenced by key s (i.e. current word in file).
		is there is no key s then one is created with an associated int 
		that is value-initialized (which for int is 0)
		*/

		// split words by hyphen delimiter
		substrs = hyphenSplit(s);
		
		for (std::vector<std::string>::iterator it_substr = substrs.begin();
			it_substr != substrs.end(); ++it_substr) {
			
			// iterator pointing to first char in the substring
			std::string::iterator it = (*it_substr).begin();

			while (it != (*it_substr).end()) {

				// check if char is acceptable
				if (isalnum(*it) ||
					std::find(punctuation.begin(),
						punctuation.end(), *it) != punctuation.end()) {

					// change char to lower casee
					*it = std::tolower(*it);
					++it;
				}
				else {
					// is punctuation to discard

					(*it_substr).erase(it);
					// maybe this is slow though and it would be better to make a copy 
					// of the array with acceptable chars using push_back.

					// no need to increment it here
				}
			}
			if ( (*it_substr).size() >= minlen) {
				++counters[*it_substr];
			}
		}		
	}

	// write results to stdout
	// header row
	std::cout << "Word\tUsage" << std::endl;
	// write the key/counts stored in maps

	for (std::map<std::string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it) {
		// need to pad words with spaces to length of max word
		//          key					  value
		std::cout << it->first << "\t" << it->second << std::endl;
	}

}

// need to ignore punctuation and b put all in lower case
// cf 03_FindURL in Ch6