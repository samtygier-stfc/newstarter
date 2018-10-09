/**
 * Skeleton main routine
 */

#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

int main(int, char **)
{
	double squareSide = 3.5;
	Square mySquare = Square::Square(squareSide);
	std::cout << mySquare.GetPerimeter() << std::endl;

	double recWidth = 2;
	double recHeight = 5;
	Rectangle myRectangle = Rectangle::Rectangle(recWidth, recHeight);
	std::cout << myRectangle.GetType() << std::endl;

	double circleRadius = 5;
	Circle myCircle = Circle::Circle(circleRadius);
	std::cout << myCircle.GetArea() << std::endl;
}