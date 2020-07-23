#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect: public Shape {

  public:
    Rect(double a, double b);

    double getArea(); 

    double getPerimeter();
  
  private:
    double side1;
    double side2;
};

#endif