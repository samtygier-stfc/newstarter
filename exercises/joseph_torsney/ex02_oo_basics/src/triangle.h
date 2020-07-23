#pragma once

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  public:
    Triangle(double b, double h);

    double getArea();

    double getPerimeter();

  private:
    double m_base;
    double m_height;

};
