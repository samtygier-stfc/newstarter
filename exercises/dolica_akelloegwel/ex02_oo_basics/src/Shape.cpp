#include "Shape.h"

Shape::Shape(double p, double a, std::string t, int n, std::string msg)
{
	perimeter = p;
	area = a;
	type = t;
	numSides = n;
	printMessage = msg;
}
double Shape::GetPerimeter() const
{
	return perimeter;
}
double Shape::GetArea() const
{
	return area;
}
std::string Shape::GetType() const
{
	return type;
}
int Shape::GetSides() const
{
	return numSides;
}
std::string Shape::GetMessage() const
{
	return printMessage;
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	os << shape.GetMessage();
	return os;
}
