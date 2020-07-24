#pragma once

#include "shape.h"

class Rect: public Shape {

  public:
    Rect(double a, double b);

    const double getArea() override; 

    const double getPerimeter() override;
  
  private:
    const double m_side1;
    const double m_side2;
};
