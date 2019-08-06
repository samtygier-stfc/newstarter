#include "../inc/Triangle.h"
#include <math.h>
#include <iomanip>
#include <iostream>


Triangle::Triangle(double base, double height)
{
	setShapeName("triangle");
	setN_sides(3);
	setSide1(base);
	setSide2(height);
}

void Triangle::printSelf()
{
	std::cout << "Shape: " << std::setw(10) << getShapeName() << std::setw(15)
		<< "Base: " << std::setw(10) << getSide1() << std::setw(15) << "Height: " << std::setw(10) << getSide2() << std::setw(15)
		<< "Perimeter: " << std::setw(10) << getPerimeter() << std::setw(15) << "Volume: " << std::setw(10) << getVolume() << std::endl;
}

double Triangle::getPerimeter()
{
	return getSide1() + 2.0*sqrt(getSide2()*getSide2() + (getSide1()*getSide1() /4.0));
}

double Triangle::getVolume()
{
	return 0.5*getSide1()*getSide2();
}