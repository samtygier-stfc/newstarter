#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ShapeBase.h"

class Triangle : public ShapeBase {
public:
  Triangle(double, double);
  ShapeBase *clone() const override;
  double getPerimeter() const override;
  double getArea() const override;
  double getBase() const;
  double getHeight() const;
private:
  const double m_base;
  const double m_height;
};

#endif // TRIANGLE_H