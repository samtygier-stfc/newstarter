#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect: public Shape {
  double side1;
  double side2;

  public:
    Rect(double a, double b): Shape("rect") {
      side1 = a;
      side2 = b;
    }

    double getPerimeter() {
      return (2*side1 + 2*side2);
    }
};

#endif