#pragma once
#include <string>
#include "BaseShape.h"

class Square : public BaseShape {
public:
  double calculateArea() override;
  double calculatePerimeter() override;
  double m_length;
  Square(double shapeLength) : BaseShape(4, "Square"), m_length{ shapeLength }{
  }
};