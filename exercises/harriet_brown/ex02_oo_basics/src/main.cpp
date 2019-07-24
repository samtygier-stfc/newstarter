/**
 * Skeleton main routine
 */
#include "Shape.h"
#include <iostream>

int main(int, char **)
{
	Shape shape1;
	shape1.setShape("square");
	shape1.setSides(2.0, 3.0);
	std::cout << "A " << shape1.getShape() << " with a width of " << shape1.getWidth() << " and a height of " 
		<< shape1.getHeight() << " will have a perimeter of " << shape1.getPerimeter() << "." << std::endl;

	Shape shape2;
	shape1.setShape("rectangle");
	shape1.setSides(2.0, 3.0);
	std::cout << "A " << shape1.getShape() << " with a width of " << shape1.getWidth() << " and a height of "
		<< shape1.getHeight() << " will have a perimeter of " << shape1.getPerimeter() << "." << std::endl;

	Shape shape3;
	shape1.setShape("circle");
	shape1.setSides(2.0, 3.0);
	std::cout << "A " << shape1.getShape() << " with a width of " << shape1.getWidth() << " and a height of "
		<< shape1.getHeight() << " will have a perimeter of " << shape1.getPerimeter() << "." << std::endl;

	Shape shape4;
	shape1.setShape("triangle");
	shape1.setSides(2.0, 3.0);
	std::cout << "A " << shape1.getShape() << " with a width of " << shape1.getWidth() << " and a height of "
		<< shape1.getHeight() << " will have a perimeter of " << shape1.getPerimeter() << "." << std::endl;

}