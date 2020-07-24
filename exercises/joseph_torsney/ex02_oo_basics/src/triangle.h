#pragma once

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  public:
    Triangle(double b, double h);

    double getArea() const override;

    double getPerimeter() const override;

  private:
    const double m_base;
    const double m_height;

};
