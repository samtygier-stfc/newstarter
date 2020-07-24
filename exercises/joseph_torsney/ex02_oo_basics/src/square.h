#pragma once

#include "shape.h"

class Square: public Shape {

  public:
    Square(double side);

    const double getArea() {
      return m_side1*m_side1;
    }

    const double getPerimeter() {
      return 4*m_side1;
    }

  private:
    int m_side1;
};
