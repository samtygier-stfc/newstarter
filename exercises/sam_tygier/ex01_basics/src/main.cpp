/**
 * Solution to C++ Basics exercise
 * 
 * Reads an ASCII file, counts word usage and outputs a stats table
 * 
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "words.h"

int main(int argv, char ** argc)
{
	if(argv != 2){
		std::cerr << "Usage:" <<std::endl;
		std::cerr << " " << argc[0] << " filename" <<std::endl;
		return 1;
	}
	std::string filename = argc[1];

	std::ifstream inputfile(filename);

	if(! inputfile){
		std::cerr << "Could not open: " << filename <<std::endl;
		return 1;
	}

	auto counts = countWords(inputfile);
	auto stats = sortCounts(counts);
	
	std::cout << std::left << std::setw(12) << "Word" << " " << "Usage" << std::endl << std::endl;
	for(const auto &wordInfo: stats){
		std::cout << std::left << std::setw(12) << wordInfo.first << " " << wordInfo.second << std::endl;
	}
}
