/**
 * Skeleton main routine
 */

#include <iostream>
#include "Square.h"

int main(int, char **)
{
	double squareSide = 3.5;
	Square mySquare = Square::Square(squareSide);
	std::cout << mySquare.GetPerimeter() << std::endl;
}