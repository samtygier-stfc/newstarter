#pragma once
#include "Shape.h"

class Rectangle: public Shape
{
public:
  //Optional third argument so that we can easily use this as a base class for Square calss.
  Rectangle(const double side1, const double side2, const std::string& shapeType = "rectangle");

private:
  void calculateArea() override;
  void calculatePerimeter() override;

  double m_side1;
  double m_side2;
};

