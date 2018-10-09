#include "Circle.h"

Circle::Circle(double r) : Shape(2 * M_PI * r, M_PI * r * r, "Circle", 1)
{
	radius = r;
}
double Circle::GetRadius()
{
	return radius;
}
void Circle::write(std::ostream & os) const
{
	os << "Circle Properties:" << std::endl;
	os << "  Radius: " << radius << std::endl;
	os << "  Perimeter: " << perimeter << std::endl;
}
