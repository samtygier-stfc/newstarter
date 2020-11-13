/**
 * Solution to Object Oriented C++ Basics exercise
 *
 * Defines some shapes and outputs some information
 *
 */

#include <iostream>

#include "shape.h"
#include "circle.h"

int main(int, char **)
{
	Circle c1(3);
	std::cout << c1.getType() << " " << c1.getSides() << " " << c1.getPerimeter() << " " << c1.getArea() << std::endl;
	std::cout << c1 << std::endl;
}
