#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(const double _base, const double _height);

	double getPerimeter() const;
	double getArea() const;
	unsigned int getNumberOfSides() const { return 3; };

private:
	double base;
	double height;
};

#endif