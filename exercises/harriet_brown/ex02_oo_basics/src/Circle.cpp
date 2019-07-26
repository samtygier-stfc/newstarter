#include "../inc/Circle.h"


Circle::Circle(double radius)
{
	setShape("circle");
	setN_sides(1);
	setSide1(radius);
}

void Circle::printSelf()
{
	std::cout << "Shape: " << std::setw(10) << getShape() << std::setw(15)
		<< "Radius: " << std::setw(10) << getSide1() << std::setw(40)
		<< "Perimeter: " << std::setw(10) << getPerimeter() << std::setw(15) << "Volume: " << std::setw(10) << getVolume() << std::endl;
}

double Circle::getPerimeter()
{
	return 2.0*getSide1()*M_PI;
}

double Circle::getVolume()
{
	return getSide1() * getSide1()*M_PI;
}