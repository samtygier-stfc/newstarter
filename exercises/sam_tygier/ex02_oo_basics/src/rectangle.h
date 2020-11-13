#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>

#include "shape.h"

class Rectangle: public Shape{
public:
	Rectangle(double side1, double side2):
	    m_side1(side1), m_side2(side2) {};
	std::string getType() const override;
	signed int getSides() const override;
	double getPerimeter() const override;
	double getArea() const override;

private:
	double m_side1;
	double m_side2;
};

#endif
