#include "Shape.h"

Shape::Shape(double a, double p)
{
	area = a;
	perimeter = p;
}
double Shape::GetPerimeter()
{
	return perimeter;
}
double Shape::GetArea()
{
	return area;
}
