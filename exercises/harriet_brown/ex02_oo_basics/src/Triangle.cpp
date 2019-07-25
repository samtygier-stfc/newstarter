#include "../inc/Triangle.h"


Triangle::Triangle(double base, double height)
{
	setShape("Triangle");
	setSide1(base);
	setSide2(height);
}

double Triangle::getPerimeter()
{
	return getSide1() + 2.0*sqrt(getSide2()*getSide2() + (getSide1()*getSide1() /4.0));
}

double Triangle::getVolume()
{
	return 0.5*getSide1()*getSide2();
}