#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon {
public:
  ShapeBase *clone() const override;
  double calculatePerimeter() override;
  double calculateArea() override;

private:
  double m_side1;
  double m_side2;
};

#endif // RECTANGLE_H