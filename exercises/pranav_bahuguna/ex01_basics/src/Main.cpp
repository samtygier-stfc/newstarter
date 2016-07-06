#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef string::iterator str_iter;
typedef map<string, int>::const_iterator map_iter;
typedef vector<pair<string, int>>::const_iterator vp_iter;

// True if character is punctuation/whitespace, otherwise false
bool is_punct(char c)
{
	static const string punct = ".,?'\"!():-";
	return (isspace(c) || find(punct.begin(), punct.end(), c) != punct.end());
}

// False if character is punctuation/whitespace, otherwise true
bool not_punct(char c)
{
	return !is_punct(c);
}

int main()
{
	str_iter i;
	string s;
	map<string, int> counters;
	ifstream infile("example.txt");
	ofstream writefile;
	writefile.open("results.txt");

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

	sort(sorted_counters.begin(), sorted_counters.end(), 
		[](auto &left, auto &right) {
		return left.second > right.second;
	});

	// write words and associated counts to text file
	writefile << "Word\tUsage\n" << endl;
	for (vp_iter it = sorted_counters.begin(); 
		it != sorted_counters.end(); it++)
		writefile << it->first << "\t" << it->second << endl;

	writefile.close();
	infile.close();

	return 0;
}