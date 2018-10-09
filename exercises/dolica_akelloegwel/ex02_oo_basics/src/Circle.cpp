#include "Circle.h"

Circle::Circle(double r) : Shape("Circle", 1)
{
	radius = r;

	SetPerimeter(2 * M_PI * r);
	SetArea(M_PI * r * r);
	SetMessage("A message about this being a circle.");
}
double Circle::GetRadius() const
{
	return radius;
}
