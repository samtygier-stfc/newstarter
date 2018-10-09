#include "Shape.h"

Shape::Shape(double p, double a, std::string t, int n)
{
	perimeter = p;
	area = a;
	type = t;
	numSides = n;
}
double Shape::GetPerimeter() const
{
	return perimeter;
}
double Shape::GetArea() const
{
	return area;
}
std::string Shape::GetType() const
{
	return type;
}
int Shape::GetSides() const
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
