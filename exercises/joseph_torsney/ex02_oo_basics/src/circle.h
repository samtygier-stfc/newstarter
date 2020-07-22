#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "shape.h"

class Circle: public Shape {
  double radius;

  public:
    Circle(double r): Shape("circle") {
      radius = r;
    } 

    double getPerimeter() {
      return 2*M_PI*radius;
    }
};

#endif