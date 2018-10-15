#include "Circle.h"

Circle::Circle(double radius) : Shape("Circle", 1)
{
	// Set the radius
	m_radius = radius;

	// Construct a message for use when overloading <<
	std::string circleMessage = "Circle Properties: \n";
	circleMessage += "  Radius: " + std::to_string(radius);
	circleMessage += CreateBaseMessage();

	SetMessage(circleMessage);
}
double Circle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}
double Circle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}
double Circle::GetRadius() const
{
	return m_radius;
}
