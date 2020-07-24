#pragma once
#include <string>
#include "BaseShape.h"

class Rectangle : public BaseShape {
public:
  double calculateArea() override;
  double calculatePerimeter() override;
  double m_length;
  double m_width;
  Rectangle(double shapeLength, double shapeWidth) : BaseShape(4, "Rectangle"), m_length{ shapeLength }, m_width{ shapeWidth } {
  }
};
