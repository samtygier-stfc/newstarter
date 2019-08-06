#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeBase.h"

class Circle : public ShapeBase {
public:
  Circle(double);
  double getPerimeter() const override;
  double getArea() const override;
  double getRadius() const;
private:
  const double m_radius;
};

#endif // CIRCLE_H