#pragma once

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  public:
    Triangle(double b, double h);

    const double getArea() override;

    const double getPerimeter() override;

  private:
    const double m_base;
    const double m_height;

};
