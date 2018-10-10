#include "Triangle.h"

Triangle::Triangle(double b, double h) : Shape("Triangle", 3)
{
	// Set the base and height values
	m_base = b;
	m_height = h;

	// Compute and set perimeter
	double perim = b + 2 * std::sqrt(h * h + b * b * 0.25);
	SetPerimeter(perim);

	// Compute and set area
	double area = b * 0.5 * h;
	SetArea(b * 0.5 * h);

	// Construct and set a message for use when overloading <<
	std::string triangleMessage = "Triangle Properties:\n";
	triangleMessage += "  Base: " + std::to_string(b) + "\n";
	triangleMessage += "  Height: " + std::to_string(h);
	triangleMessage += CreateBaseMessage();

	SetMessage(triangleMessage);
}
double Triangle::GetBase() const
{
	return m_base;
}
double Triangle::GetHeight() const
{
	return m_height;
}