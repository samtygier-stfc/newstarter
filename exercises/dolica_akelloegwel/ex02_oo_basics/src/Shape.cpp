#include "Shape.h"

Shape::Shape(std::string t, int n)
{
	type = t;
	numSides = n;

	perimeter = 0;
	area = 0;
	printMessage = "";
}
double Shape::GetPerimeter() const
{
	return perimeter;
}
void Shape::SetPerimeter(double p)
{
	perimeter = p;
}
double Shape::GetArea() const
{
	return area;
}
void Shape::SetArea(double a)
{
	area = a;
}
std::string Shape::GetType() const
{
	return type;
}
int Shape::GetSides() const
{
	return numSides;
}
void Shape::SetSides(int s)
{
	numSides = s;
}
std::string Shape::GetMessage() const
{
	return printMessage;
}
void Shape::SetMessage(std::string msg)
{
	printMessage = msg;
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	os << shape.GetMessage();
	return os;
}
