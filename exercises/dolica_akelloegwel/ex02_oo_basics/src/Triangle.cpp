#include "Triangle.h"

Triangle::Triangle(double b, double h) : Shape(b + 2 * std::sqrt(h * h + b * b * 0.25), b * 0.5 * h, "Triangle", 3, "This is a triangle.")
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