/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

#ifndef _Shape_h
#define _Shape_h

int main(int, char **)
{
	double squareSide = 2;
	Square mySquare = Square::Square(squareSide);

	double recWidth = 2;
	double recHeight = 5;
	Rectangle myRectangle = Rectangle::Rectangle(recWidth, recHeight);

	double circleRadius = 5;
	Circle myCircle = Circle::Circle(circleRadius);

	double triangleBase = 3;
	double triangleHeight = 4;
	Triangle myTriangle = Triangle::Triangle(triangleBase, triangleHeight);

	std::vector<Shape> myShapes;

	myShapes.push_back(mySquare);
	myShapes.push_back(myRectangle);
	myShapes.push_back(myCircle);
	myShapes.push_back(myTriangle);

	for (std::vector<Shape>::iterator it = myShapes.begin(); it != myShapes.end(); it++) {
		std::cout << it->GetType() << std::endl;
	}

	ShapeSorter shapeSorter = ShapeSorter::ShapeSorter();
	shapeSorter.PrintType(myShapes,"Triangle");
}

#endif