#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect: public Shape {
  int a;
  int b;

  public:
    Rect(int a, int b): Shape(2) {
      a = a;
      b = b;
    }
};

#endif