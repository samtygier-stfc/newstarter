#include "../inc/Rectangle.h"
#include <math.h>
#include <iomanip>
#include <iostream>


Rectangle::Rectangle(double width, double height)
{
	setShapeName("rectangle");
	setN_sides(4);
	setSide1(width);
	setSide2(height);
}

void Rectangle::printSelf()
{
	std::cout << "Shape: " << std::setw(10) << getShapeName() << std::setw(15)
		<< "Width: " << std::setw(10) << getSide1() << std::setw(15) << "Height: " << std::setw(10) << getSide2() << std::setw(15)
		<< "Perimeter: " << std::setw(10) << getPerimeter() << std::setw(15) << "Volume: " << std::setw(10) << getVolume() << std::endl;
}

double Rectangle::getPerimeter()
{
	return 2.0*getSide1() + 2.0*getSide2();
}

double Rectangle::getVolume()
{
	return getSide1() * getSide2();
}