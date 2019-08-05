#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
  Circle();
  Circle(double radius);
  virtual double perimeter() const override;
  virtual double area() const override;

private:
  double m_radius;
};
#endif // CIRCLE_H
