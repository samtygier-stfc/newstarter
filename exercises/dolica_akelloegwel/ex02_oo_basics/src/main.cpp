/**
 * Skeleton main routine
 */

#include <iostream>
#include "Square.h"
#include "Rectangle.h"

int main(int, char **)
{
	double squareSide = 3.5;
	Square mySquare = Square::Square(squareSide);
	std::cout << mySquare.GetPerimeter() << std::endl;

	double recWidth = 2;
	double recHeight = 5;
	Rectangle myRectangle = Rectangle::Rectangle(recWidth, recHeight);
	std::cout << myRectangle.getType() << std::endl;
}