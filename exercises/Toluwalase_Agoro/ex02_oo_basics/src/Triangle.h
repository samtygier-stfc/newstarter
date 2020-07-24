#pragma once
#include <string>
#include "BaseShape.h"

class Triangle : public BaseShape {
public:
  double m_base;
  double m_height;
  double calculateArea() override;
  double calculatePerimeter() override;
  Triangle(double shapeBase, double shapeHeight) : BaseShape(3, "Triangle"), m_base{ shapeBase }, m_height{ shapeHeight }{
  }
};