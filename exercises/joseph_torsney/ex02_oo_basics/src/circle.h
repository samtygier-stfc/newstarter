#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "shape.h"

class Circle: public Shape {
  double radius;

  public:
    Circle(double r): Shape("circle", 1) {
      radius = r;
    } 

    double getArea() {
      return M_PI*pow(radius, 2);
    }

    double getPerimeter() {
      return 2*M_PI*radius;
    }
};

#endif