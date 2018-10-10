#include "Triangle.h"

Triangle::Triangle(double base, double height) : Shape("Triangle", 3)
{
	// Set the base and height values
	m_base = base;
	m_height = height;

	// Compute and set perimeter
	double perim = base + 2 * std::sqrt(height * height + base * base * 0.25);
	SetPerimeter(perim);

	// Compute and set area
	double area = base * 0.5 * height;
	SetArea(area);

	// Construct and set a message for use when overloading <<
	std::string triangleMessage = "Triangle Properties:\n";
	triangleMessage += "  Base: " + std::to_string(base) + "\n";
	triangleMessage += "  Height: " + std::to_string(height);
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