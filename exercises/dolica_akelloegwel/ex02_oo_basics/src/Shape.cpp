#include "Shape.h"

Shape::Shape(std::string t, int n)
{
	// Set type and number of sides
	m_type = t;
	m_numSides = n;

	// Set default member variable values
	// Compute during subclass initialisation
	m_perimeter = 0;
	m_area = 0;
	m_printMessage = "";
}
double Shape::GetPerimeter() const
{
	return m_perimeter;
}
void Shape::SetPerimeter(double p)
{
	m_perimeter = p;
}
double Shape::GetArea() const
{
	return m_area;
}
void Shape::SetArea(double a)
{
	m_area = a;
}
std::string Shape::GetType() const
{
	return m_type;
}
int Shape::GetSides() const
{
	return m_numSides;
}
void Shape::SetSides(int s)
{
	m_numSides = s;
}
std::string Shape::CreateBaseMessage()
{
	// Create a basic message without subclass info to act as a template when overloading <<
	return "\n  Perimeter: " + std::to_string(m_perimeter) + "\n  Area: " + std::to_string(m_area) + "\n";
}
std::string Shape::GetMessage() const
{
	return m_printMessage;
}
void Shape::SetMessage(std::string msg)
{
	// Set the print message after it has been constructed in the subclass
	m_printMessage = msg;
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	// Retrieve the shape message and print
	os << shape.GetMessage();
	return os;
}
