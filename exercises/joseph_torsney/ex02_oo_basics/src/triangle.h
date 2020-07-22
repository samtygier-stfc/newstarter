#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  double base;
  double height;

  public:
    Triangle(double b, double h): Shape("triangle") {
      base = b;
      height = h;
    }

    double getArea() {
      return 0.5 * base * height;
    }

    double getPerimeter() {
      return base + 2*sqrt(pow(height, 2) + (pow(base, 2) / 4));
    }
};

#endif