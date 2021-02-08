#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
  Triangle(const double height, const double base);

private:
  void calculateArea() override;
  void calculatePerimeter() override;

  double m_height;
  double m_base;
};

