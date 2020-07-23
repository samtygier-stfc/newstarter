#pragma once

#include <math.h>
#include "shape.h"

class Circle: public Shape {
  public:
    Circle(double r);

    double getArea();

    double getPerimeter();

  private:
    double radius;
};
