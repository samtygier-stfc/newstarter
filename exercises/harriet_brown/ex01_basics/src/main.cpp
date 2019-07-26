/**
 * Program to count words from a ascii file
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void remove_punctuation_in_string(std::string &data)
{
	std::vector<std::string> puntuation{ ".", ",", "?", "!", "\'", "\"", "(", ")", ":", "--", ";"};
	for (auto x : puntuation) {
		while (data.find(x) != std::string::npos) {
			data.replace(data.find(x), 1, " ");
		}
	}
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return;
}

void print_map_by_value(std::map<std::string, int> map_to_print)
{
	std::ofstream result_file;
	result_file.open("word_count.txt");
	std::cout << std::setw(18) << "Word" << std::setw(12) << "Count" << std::endl;
	result_file << std::setw(18) << "Word" << std::setw(12) << "Count" << std::endl;
	std::string max_key;
	int max_val;
	while (map_to_print.size() > 0) {
		max_val = 0;
		for (auto it = map_to_print.begin(); it != map_to_print.end(); ++it) {
			if (it->second > max_val) {
				max_val = it->second;
				max_key = it->first;
			}
		}
		std::cout << std::setw(18) << max_key << std::setw(12) << max_val << std::endl;
		result_file << std::setw(18) << max_key << std::setw(12) << max_val << std::endl;
		map_to_print.erase(max_key);
		max_val = 0;
	}
	return;
}

int main(int argc, char* argv[])
{
	std::ifstream ascii_file;
	std::string line;
	std::stringstream str_strm;
	std::string tmp;
	std::vector<std::string> words;
	std::map<std::string, int> word_count_map;
	// Check the number of parameters
	if (argc < 2) {
		std::cerr << argv[0] << " needs to be given a file directory as an argument" << std::endl;
		return 0;
	}
	ascii_file.open(argv[1]);
	if (!ascii_file) {
		std::cerr << "Unable to open file " << argv[1];
		exit(1);   // call system to stop
	}
	while (std::getline(ascii_file, line)) {
		remove_punctuation_in_string(line);
		str_strm << line << " ";
	}
	ascii_file.close();
	while (str_strm >> tmp) {
		words.push_back(tmp);
	}
	
	for (unsigned int i = 0; i < words.size(); i++) {
		if (words[i].size() > 4) {
			if (word_count_map.find(words[i]) != word_count_map.end()) {
				word_count_map[words[i]]++;
			}
			else {
				word_count_map[words[i]] = 1;
			}
		}
	}
	print_map_by_value(word_count_map);
	return 0;
}
