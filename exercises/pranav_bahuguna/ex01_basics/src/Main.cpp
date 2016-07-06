#include <iostream>
#include <map>
#include <string>

using namespace std;

// Determines whether a character is part of the list of punctuation
bool is_punct(char c)
{
	static const string punct = ".,?'\"!():-";
	return (find(punct.begin(), punct.end(), c) != punct.end());
}

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
		// skip over leading blanks or punctuation
		while (isspace(s[i]) || is_punct(s[i]))
			i++;

		// find end of next word
		int j = i;
		while (j != s.size() && !isspace(s[j]) && !is_punct(s[j]))
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