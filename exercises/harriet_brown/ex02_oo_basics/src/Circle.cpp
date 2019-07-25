#include "../inc/Circle.h"


Circle::Circle(double radius)
{
	setShape("Circle");
	setSide1(radius);
}

double Circle::getPerimeter()
{
	return 2.0*getSide1()*M_PI;
}

double Circle::getVolume()
{
	return getSide1() * getSide1()*M_PI;
}