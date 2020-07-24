#pragma once

#include <math.h>
#include "shape.h"

class Circle: public Shape {
  public:
    Circle(double r);

    double getArea() const override;

    double getPerimeter() const override;

  private:
    const double m_radius;
};
