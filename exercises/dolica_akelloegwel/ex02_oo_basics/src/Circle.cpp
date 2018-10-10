#include "Circle.h"

Circle::Circle(double radius) : Shape("Circle", 1)
{
	// Set the radius
	m_radius = radius;

	// Compute and set circle perimeter
	double perimeter = 2 * M_PI * radius;
	SetPerimeter(perimeter);

	// Compute and set circle area
	double area = M_PI * radius * radius;
	SetArea(area);

	// Construct a message for use when overloading <<
	std::string circleMessage = "Circle Properties: \n";
	circleMessage += "  Radius: " + std::to_string(radius);
	circleMessage += CreateBaseMessage();

	SetMessage(circleMessage);
}
double Circle::GetRadius() const
{
	return m_radius;
}
