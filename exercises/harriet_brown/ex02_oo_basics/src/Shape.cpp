#include "../inc/Shape.h"


Shape::Shape()
{
}

void Shape::setShape(const std::string type)
{
	shape = type;
}

std::string Shape::getShape()
{
	return shape;
}

void Shape::setN_sides(int n)
{
	n_sides = n;
}

int Shape::getN_sides()
{
	return n_sides;
}

void Shape::setSide1(double side)
{
	side1 = side;
}

double Shape::getSide1()
{
	return side1;
}

void Shape::setSide2(double side)
{
	side2 = side;
}

double Shape::getSide2()
{
	return side2;
}