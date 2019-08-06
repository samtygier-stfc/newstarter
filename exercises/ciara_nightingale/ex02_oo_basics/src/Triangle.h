#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape {
public:
  ///default constructor to initialise the triangle to zero if no arguments are given
  Triangle();
	///constructor to initialise a triangle with required dimentions
  Triangle(double base, double height);
	///calulate the perimeter and return the value
  double perimeter() const override;
	///calculate the area and return the value
  double area() const override;

private:
  double m_base;
  double m_height;
};
#endif // TRIANGLE_H
