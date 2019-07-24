#include "Shape.h"


Shape::Shape()
{
}

void Shape::setShape(std::string type)
{
	shape = type;
}

void Shape::setHeight(double high)
{
	height = high;
	if (shape == "Square" || shape == "circle") {
		width = height;
	}
}

void Shape::setWidth(double wid)
{
	width = wid;
	if (shape == "Square" || shape == "circle") {
		height = width;
	}
}

void Shape::setSides(double side1, double side2)
{
	width = side1;
	if (shape == "square" || shape == "circle") {
		height = width;
	}
	else {
		height = side2;
	}
}

std::string Shape::getShape()
{
	return shape;
}

double Shape::getHeight()
{
	return height;
}

double Shape::getWidth()
{
	return width;
}

std::vector<double> Shape::getSides()
{
	std::vector<double> sides;
	sides.push_back(height);
	if (shape == "triangle" || shape == "rectangle") {
		sides.push_back(width);
	}
	return sides;
}

double Shape::getPerimeter()
{
	double parimiter;
	if (shape == "square" || shape == "rectangle") {
		parimiter = 4.0*height;
	}
	if (shape == "circle") {
		parimiter = 2.0*height*M_PI;
	}
	if (shape == "triangle") {
		parimiter = width + 2.0*sqrt(height*height+(width*width)/4.0);
	}
	return parimiter;
}