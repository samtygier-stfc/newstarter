#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
public:
  Rectangle();
  Rectangle(double width);
  Rectangle(double width, double height);
  virtual double perimeter() const override;
  virtual double area() const override;

private:
  double m_width;
  double m_height;
};
#endif // RECTANGLE_H
