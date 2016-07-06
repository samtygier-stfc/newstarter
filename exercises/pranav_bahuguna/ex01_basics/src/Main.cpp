#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef string::iterator str_iter;
typedef map<string, int>::const_iterator map_iter;
typedef vector<pair<string, int>>::const_iterator vp_iter;

// True if character is punctuation/whitespace, otherwise false
bool is_punct(char c)
{
	static const string punct = ".,?\"!():-";
	return (isspace(c) || find(punct.begin(), punct.end(), c) != punct.end());
}

// False if character is punctuation/whitespace, otherwise true
bool not_punct(char c)
{
	return !is_punct(c);
}

int main(int argc, char* argv[])
{
	ifstream infile;
	ofstream outfile;

	try 
	{
		// I/O file exception handling
		if (argc < 2)
			throw invalid_argument("Error: ");

		infile.open(argv[1]);
		if (!infile) 
			throw ifstream::failure("Error opening input file");

		outfile.open("results.txt");
		if (!outfile) 
			throw ofstream::failure("Error opening output file");

		str_iter i;
		string s;
		map<string, int> counters;

		while (getline(infile, s))
		{
			// all alphanumeric chars set to lowercase (for case insensitivity)
			i = s.begin();
			while (i != s.end()) {
				*i = tolower(*i);
				i++;
			}

			i = s.begin();
			while (i != s.end())
			{
				// skip over leading blanks or punctuation
				i = find_if(i, s.end(), not_punct);

				// find end of next word
				str_iter j = find_if(i, s.end(), is_punct);

				// if non-whitespace characters found, it is a word
				if (i != j) {
					// only words longer than 4 characters are included
					if (distance(i, j) > 4)
						counters[string(i, j)]++;
					i = j;
				}
			}
		}

		// Sorts map by value into a a new vector sorted_counters
		vector<pair<string, int>> sorted_counters;
		for (map_iter it = counters.begin(); it != counters.end(); it++)
			sorted_counters.push_back(*it);

		std::sort(sorted_counters.begin(), sorted_counters.end(),
			[](auto &left, auto &right) {
			return left.second > right.second;
		});

		// write words and associated counts to text file
		outfile << setw(20) << left << "Word" << setw(20) << "Usage\n" << endl;
		for (vp_iter it = sorted_counters.begin();
		it != sorted_counters.end(); it++) {
			outfile << left << setw(20) << it->first << setw(20)
				<< it->second << endl;
		}

		outfile.close();
		infile.close();
	}
	catch (invalid_argument &err)
	{
		cerr << err.what() << "Less than 1 arguments provided" << endl;
	}
	catch (ios_base::failure &err)
	{
		cerr << err.what() << endl;
		return -1;
	}

	return 0;
}