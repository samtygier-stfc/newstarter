#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int i = 0;
	string s;
	map<string, int> counters;

	// obtain user input
	cout << "Type a sentence: ";
	getline(cin, s);

	while (i != s.size())
	{
		// skip over leading blanks or hyphens
		while (isspace(s.at(i)) || s[i] == '-')
			i++;

		// find end of next word
		int j = i;
		while (j != s.size() && !isspace(s[j]) && s[j] != '-')
			j++;
		
		// if non-whitespace characters found, it is a word
		if (i != j) {
			// only words longer than 4 characters are included
			if (j - i > 4)
				counters[s.substr(i, j - i)]++;
			i = j;
		}
	}

	// write words and associated counts
	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}

	return 0;
}