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

struct key {
	/*
	to be used as key for a map
	*/
	int count = 0;
	std::string word = "";
};

bool operator<(const key& k1, const key& k2)
{
	/*
	Overload < operator for key struct with key1.count > key2.count)
	As want keys to be sorted in map by descending order (default is ascending)
	*/
	return (k1.count > k2.count);
}

std::map<key, int> convertMap(std::map<std::string, int> map_in) {
	/*
	Function takes a map and returns a new map object
	where the key is s struct datatype key that can be sorted as desired
	*/

	key akey;
	std::map<key, int> map_out;

	for (std::map<std::string, int>::const_iterator it = map_in.begin();
		it != map_in.end(); ++it) {

		akey.count = it->second;
		akey.word = it->first;

		map_out[akey] = 0; // doesn't matter what the value is...
	}
	return map_out;
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

	// punctuation to remove
	static const std::string punctuation = ".,?'\"!():";

	std::string s;
	std::vector<std::string> substrs;
	const std::string::size_type minlen = 5;
	std::string::size_type maxlen = minlen;
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
				if (isalpha(*it) ||
					std::find(punctuation.begin(),
						punctuation.end(), *it) == punctuation.end()) {

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
				// update max length of strings so far
				maxlen = std::max(maxlen,(*it_substr).size());
			}
		}		
	}

	// need to write word in descending order of appearence
	// convert map to another map with a struct as the key
	std::map<key, int> sortmap = convertMap(counters);

	// write results to stdout
	// header row
	std::cout << "Word\tUsage" << std::endl;
	key akey;
	std::string word;
	// write the key/counts stored in sortmap
	for (std::map<key, int>::const_iterator it = sortmap.begin();
		it != sortmap.end(); ++it) {

		akey = it->first;
		word = (akey.word);

		std::cout << word.append(maxlen-size(word),' ')  << akey.count << std::endl;
	}
	std::cout << "Max word length is:\t" << maxlen << std::endl;
}