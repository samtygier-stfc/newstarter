#include "../inc/Shape.h"


Shape::Shape()
{
	shape = "shape";
	side1 = 0.0;
	side2 = 0.0;
	n_sides = 0;
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