#include "Triangle.h"

Triangle::Triangle(double b, double h) : Shape(b + 2 * std::sqrt(h * h + b * b * 0.25), b * 0.5 * h, "Triangle", 3)
{
	base = b;
	height = h;
}
double Triangle::GetBase() const
{
	return base;
}
double Triangle::GetHeight() const
{
	return height;
}
void Triangle::write(std::ostream & os) const
{
	os << "This is a triangle." << std::endl;
	os << this->GetBase() << std::endl;
}