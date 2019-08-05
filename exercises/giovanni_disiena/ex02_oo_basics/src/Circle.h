#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeBase.h"

class Circle : public ShapeBase {
public:
  ShapeBase *clone() const override;
  double calculatePerimeter() override;
  double calculateArea() override;

private:
  double m_radius;
};

#endif // CIRCLE_H