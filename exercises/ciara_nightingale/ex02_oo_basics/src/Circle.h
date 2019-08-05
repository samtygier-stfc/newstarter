#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
	//constructor if no arguments are given
  Circle();
	//constructor to create a circle of the given size
  Circle(double radius);
	//functions to calculate and return the perimeter and areaof the circle as a value of type double
  virtual double perimeter() const override;
  virtual double area() const override;

private:
  double m_radius;
};
#endif // CIRCLE_H
