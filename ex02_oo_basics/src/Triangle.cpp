#include "Triangle.h"

#include <cmath>


Triangle::Triangle(const double _base, const double _height)
	: base{ _base }, height{ _height }, Shape{ ShapeType::Triangle }
{
}

double Triangle::getPerimeter() const
{
	return 2 * height + base;
}

double Triangle::getArea() const
{
	return base + 2.0 * sqrt(pow(height, 2.0) + pow(base, 2.0)/4.0);
}