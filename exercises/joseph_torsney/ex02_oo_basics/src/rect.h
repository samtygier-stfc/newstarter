#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect: public Shape {
  int side1;
  int side2;

  public:
    Rect(int a, int b): Shape("rect") {
      side1 = a;
      side2 = b;
    }

    double getPerimeter() {
      return (double) (2*side1 + 2*side2);
    }
};

#endif