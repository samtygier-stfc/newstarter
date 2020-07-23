#pragma once

#include "shape.h"

class Rect: public Shape {

  public:
    Rect(double a, double b);

    double getArea(); 

    double getPerimeter();
  
  private:
    double m_side1;
    double m_side2;
};
