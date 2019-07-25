#include "../inc/Rectangle.h"


Rectangle::Rectangle(double width, double height)
{
	setShape("rectangle");
	setN_sides(4);
	setSide1(width);
	setSide2(height);
}

double Rectangle::getPerimeter()
{
	return 2.0*getSide1() + 2.0*getSide2();
}

double Rectangle::getVolume()
{
	return getSide1() * getSide2();
}