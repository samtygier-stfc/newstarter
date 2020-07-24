#pragma once

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  public:
    Triangle(double b, double h);

    const double getArea() override;

    const double getPerimeter() override;

  private:
    double m_base;
    double m_height;

};
