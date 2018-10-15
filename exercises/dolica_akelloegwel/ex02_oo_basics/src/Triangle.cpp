#include "Triangle.h"

Triangle::Triangle(double base, double height) : Shape(3)
{
	// Set the base and height values
	m_base = base;
	m_height = height;

	// Construct and set a message for use when overloading <<
	std::string triangleMessage = "Triangle Properties:\n";
	triangleMessage += "  Base: " + std::to_string(base) + "\n";
	triangleMessage += "  Height: " + std::to_string(height);
	triangleMessage += CreateBaseMessage();

	SetMessage(triangleMessage);
}
double Triangle::GetPerimeter() const
{
	return m_base + 2 * std::sqrt(m_height * m_height + m_base * m_base * 0.25);
}
double Triangle::GetArea() const
{
	return m_base * 0.5 * m_height;
}
std::string Triangle::GetType() const
{
	return "Triangle";
}
double Triangle::GetBase() const
{
	return m_base;
}
double Triangle::GetHeight() const
{
	return m_height;
}
