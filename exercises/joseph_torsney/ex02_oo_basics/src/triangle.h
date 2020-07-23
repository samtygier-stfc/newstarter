#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "math.h"
#include "shape.h"

class Triangle: public Shape {
  public:
    Triangle(double b, double h);

    double getArea();

    double getPerimeter();

  private:
    double base;
    double height;

};

#endif