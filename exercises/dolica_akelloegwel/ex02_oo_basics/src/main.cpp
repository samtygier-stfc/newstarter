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
	// Create various shapes
	double squareSide = 2.5;
	Square mySquare = Square::Square(squareSide);

	double recWidth = 2;
	double recHeight = 5;
	Rectangle myRectangle = Rectangle::Rectangle(recWidth, recHeight);

	double circleRadius = 5;
	Circle myCircle = Circle::Circle(circleRadius);

	double triangleBase = 3;
	double triangleHeight = 4;
	Triangle myTriangle = Triangle::Triangle(triangleBase, triangleHeight);

	// Create a vector and place the shapes in it
	std::vector<Shape> myShapes;

	myShapes.push_back(mySquare);
	myShapes.push_back(myRectangle);
	myShapes.push_back(myCircle);
	myShapes.push_back(myTriangle);

	// Examine behaviour of the shape sorter
	ShapeSorter shapeSorter = ShapeSorter::ShapeSorter();
	shapeSorter.PrintBasedOnType(myShapes, "Circle");
	shapeSorter.PrintBasedOnType(myShapes, "Triangle");
	shapeSorter.PrintBasedOnNSides(myShapes, 4);
	shapeSorter.SortByAreaDesc(myShapes);
	shapeSorter.SortByPerimeterDesc(myShapes);
}

#endif