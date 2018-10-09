#include "Triangle.h"

Triangle::Triangle(double b, double h) : Shape("Triangle", 3)
{
	base = b;
	height = h;

	SetPerimeter(b + 2 * std::sqrt(h * h + b * b * 0.25));
	SetArea(b * 0.5 * h);
	SetMessage("This is a triangle.");
}
double Triangle::GetBase() const
{
	return base;
}
double Triangle::GetHeight() const
{
	return height;
}