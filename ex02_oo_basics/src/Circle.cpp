#include "Circle.h"


Circle::Circle(const double _radius)
	: radius{ _radius }, Shape{ ShapeType::Circle }
{
}

double Circle::getPerimeter() const
{
	return 2 * MathConstants::Pi * radius;
}


double Circle::getArea() const
{
	return MathConstants::Pi * radius * radius;
}