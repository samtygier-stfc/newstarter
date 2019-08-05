#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeBase.h"

class Rectangle : public ShapeBase {
public:
  Rectangle(double, double);
  ShapeBase *clone() const override;
  double calculatePerimeter() const override;
  double calculateArea() const override;

private:
  const double m_length;
  const double m_width;
};

#endif // RECTANGLE_H