#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect: public Shape {
  int side1;
  int side2;

  public:
    Rect(int side1, int side2): Shape("rect") {
      side1 = side1;
      side2 = side2;
    }
};

#endif