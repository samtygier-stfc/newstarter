#include "../inc/getInput.h"


void getInput(std::string question_text, int &ans)
{
	std::cout << question_text;
	std::cin >> ans;
	std::cout << std::endl;
	return;
}

void getInput(std::string question_text, double &ans)
{
	std::cout << question_text;
	std::cin >> ans;
	std::cout << std::endl;
	return;
}

void getInput(std::string question_text, std::string &ans)
{
	std::cout << question_text;
	std::cin >> ans;
	std::cout << std::endl;
	return;
}