#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

#include "shape.h"

class Triangle: public Shape{
public:
	Triangle(double height, double base)
	    : m_height(height), m_base(base) {};
	std::string getType() const override;
	signed int getSides() const override;
	double getPerimeter() const override;
	double getArea() const override;

private:
	double m_height;
	double m_base;
};

#endif
