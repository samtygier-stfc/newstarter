#include "Shape.h"

Shape::Shape()
{
	// Set default member variable values
	// Compute during subclass initialisation
	m_printMessage = "";
}
Shape::~Shape()
{
}
std::string Shape::CreateBaseMessage()
{
	// Create a basic message without subclass info to act as a template when overloading <<
	return "\n  Perimeter: " + std::to_string(GetPerimeter()) + "\n  Area: " + std::to_string(GetArea()) + "\n";
}
std::string Shape::GetMessage() const
{
	return m_printMessage;
}
void Shape::SetMessage(std::string printMessage)
{
	// Set the print message after it has been constructed in the subclass
	m_printMessage = printMessage;
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	// Retrieve the shape message and print
	os << shape.GetMessage();
	return os;
}
