#include "Shape.h"

Shape::Shape(double p, double a, std::string t, int n)
{
	perimeter = p;
	area = a;
	type = t;
	numSides = n;
}
double Shape::GetPerimeter()
{
	return perimeter;
}
double Shape::GetArea()
{
	return area;
}
std::string Shape::GetType()
{
	return type;
}
int Shape::GetSides()
{
	return numSides;
}
void Shape::write(std::ostream& os) const
{
	// Do nothing
}
std::ostream & operator<<(std::ostream & os, const Shape & shape)
{
	shape.write(os);
	return os;
}
