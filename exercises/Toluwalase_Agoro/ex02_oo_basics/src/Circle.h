#pragma once
#include <string>
#include "BaseShape.h"

class Circle : public BaseShape {
public:
  double m_radius;
  double calculateArea() override;
  double calculatePerimeter() override;
  Circle(double shapeRadius) : BaseShape(1, "Circle"), m_radius{ shapeRadius }{
  }
};