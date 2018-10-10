#include "Circle.h"

Circle::Circle(double r) : Shape("Circle", 1)
{
	// Set the radius
	m_radius = r;

	// Compute and set circle perimeter
	double perim = 2 * M_PI * r;
	SetPerimeter(perim);

	// Compute and set circle area
	double ar = M_PI * r * r;
	SetArea(ar);

	// Construct a message for use when overloading <<
	std::string circleMessage = "Circle Properties: \n";
	circleMessage += "  Radius: " + std::to_string(r);
	circleMessage += CreateBaseMessage();

	SetMessage(circleMessage);
}
double Circle::GetRadius() const
{
	return m_radius;
}
