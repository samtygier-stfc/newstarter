#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeBase.h"

class Circle : public ShapeBase {
public:
  Circle(double);
  ShapeBase *clone() const override;
  double calculatePerimeter() const override;
  double calculateArea() const override;

private:
  const double m_radius;
};

#endif // CIRCLE_H