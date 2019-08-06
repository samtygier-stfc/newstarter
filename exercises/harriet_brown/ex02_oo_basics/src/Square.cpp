#include "../inc/Square.h"
#include <math.h>
#include <iomanip>
#include <iostream>


Square::Square(double side)
{
	setShapeName("square");
	setN_sides(4);
	setSide1(side);
}

void Square::printSelf()
{
	std::cout << "Shape: " << std::setw(10) << getShapeName() << std::setw(15)
		<< "Side: " << std::setw(10) << getSide1() << std::setw(40)
		<< "Perimeter: " << std::setw(10) << getPerimeter() << std::setw(15) << "Volume: " << std::setw(10) << getVolume() << std::endl;
}

double Square::getPerimeter()
{
	return 4.0*getSide1();
}

double Square::getVolume() 
{
	return getSide1() * getSide1();
}