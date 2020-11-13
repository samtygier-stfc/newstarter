#ifndef Circle_h
#define Circle_h

#include "Shape.h"

namespace MathConstants {
	constexpr double Pi = 3.14159265358979323846;
}

class Circle : public Shape
{
public:
	Circle(const double _radius);

	double getPerimeter() const;
	double getArea() const;
	unsigned int getNumberOfSides() const { return 1; };

private:
	double radius;
};

#endif