#ifndef SQUARE_H
#define SQUARE_H

#include <string>

#include "shape.h"

class Square: public Shape{
public:
	Square(double side1): m_side1(side1) {};
	std::string getType() const override;
	signed int getSides() const override;
	double getPerimeter() const override;
	double getArea() const override;

private:
	double m_side1;
};

#endif
