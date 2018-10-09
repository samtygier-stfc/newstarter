#include "Circle.h"

Circle::Circle(double r) : Shape(2 * M_PI * r, M_PI * r * r, "Circle", 1, "A message about this being a circle.")
{
	radius = r;
}
double Circle::GetRadius() const
{
	return radius;
}
