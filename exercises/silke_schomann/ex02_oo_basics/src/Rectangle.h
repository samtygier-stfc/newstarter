#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(const double _side1, const double _side2, const bool isSquare = false);

	double getPerimeter() const;
	double getArea() const;
	unsigned int getNumberOfSides() const { return 4; };

private: 
	double side1;
	double side2;
};

#endif