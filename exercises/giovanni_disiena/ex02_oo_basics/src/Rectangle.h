#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeBase.h"

class Rectangle : public ShapeBase {
public:
  // constructs Rectangle object
  Rectangle(double, double);
  Rectangle(double);
  // overriden functions
  double getPerimeter() const override;
  double getArea() const override;
  double getLength() const;
  double getWidth() const;
private:
  const double m_length;
  const double m_width;
};

#endif // RECTANGLE_H