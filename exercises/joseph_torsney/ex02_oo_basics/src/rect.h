#pragma once

#include "shape.h"

class Rect: public Shape {

  public:
    Rect(double a, double b);

    double getArea() const override; 

    double getPerimeter() const override;
  
  private:
    const double m_side1;
    const double m_side2;
};
