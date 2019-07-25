#include "../inc/Square.h"


Square::Square(double side)
{
	setShape("square");
	setN_sides(4);
	setSide1(side);
}

double Square::getPerimeter()
{
	return 4.0*getSide1();
}

double Square::getVolume() 
{
	return getSide1() * getSide1();
}