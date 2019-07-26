#include "../inc/getInput.h"


void getInput(std::string question_text, int &ans)
{
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
	return;
}

void getInput(std::string question_text, double &ans)
{
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
	return;
}

void getInput(std::string question_text, std::string &ans)
{
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
	return;
}