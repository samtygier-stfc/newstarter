#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
public:
  ShapeBase *clone() const override;
  double calculatePerimeter() override;
  double calculateArea() override;

private:
  double m_base;
  double m_height;
};

#endif // TRIANGLE_H