#ifndef GETINPUT_H
#define GETINPUT_H

#include <iostream>
#include <string>
#include <limits>

template<typename ResultType>
ResultType getInput(const std::string& question_text) {
	ResultType ans;
	std::cout << question_text;
	std::cin >> ans;
	std::cout << std::endl;
	while (1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You have entered wrong input" << std::endl;
			std::cin >> ans;
		}
		if (!std::cin.fail())
			break;
	}
	return ans;
}

#endif