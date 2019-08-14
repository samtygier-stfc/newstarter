#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape {
public:
	///Constructor to initialise a triangle with required dimentions.
  Triangle(double base, double height);
	///Calulate the perimeter and return the value.
  double perimeter() const override;
	///Calculate the area and return the value.
  double area() const override;

private:
  double const m_base;
  double const m_height;
};
#endif // TRIANGLE_H
