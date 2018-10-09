#include "Shape.h"

Shape::Shape(std::string t, int n)
{
	// Set type and number of sides
	type = t;
	numSides = n;

	// Compute extra shape information outside of superclass constructor
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
std::string Shape::CreateBaseMessage()
{
	// Create a basic message without subclass info to act as a template when overloading <<
	return "\n  Perimeter: " + std::to_string(perimeter) + "\n  Area: " + std::to_string(area) + "\n";
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
	// Retrieve the shape message and print
	os << shape.GetMessage();
	return os;
}
