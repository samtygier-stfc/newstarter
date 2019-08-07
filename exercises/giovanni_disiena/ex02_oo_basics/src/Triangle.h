#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ShapeBase.h"

class Triangle : public ShapeBase {
public:
  // constructs Triangle object
  Triangle(double, double);
  // overriden functions
  double getPerimeter() const override;
  double getArea() const override;
  double getBase() const;
  double getHeight() const;
private:
  const double m_base;
  const double m_height;
};

#endif // TRIANGLE_H