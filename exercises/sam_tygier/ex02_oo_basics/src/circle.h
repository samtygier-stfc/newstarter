#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

#include "shape.h"

class Circle: public Shape{
public:
	Circle(double radius): m_radius(radius) {};
	std::string getType() const override;
	signed int getSides() const override;
	double getPerimeter() const override;
	double getArea() const override;

private:
	double m_radius;
};

#endif
