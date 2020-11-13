#include "Rectangle.h"

Rectangle::Rectangle(const double _side1, const double _side2, const bool isSquare)
	: side1{ _side1 }, side2{ _side2 }, Shape{ isSquare ? ShapeType::Square : ShapeType::Rectangle }
{
}

double Rectangle::getPerimeter() const
{
	return 2 * (side1 + side2);
}

double Rectangle::getArea() const
{
	return side1 * side2;
}