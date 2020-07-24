#pragma once

#include "shape.h"

class Square: public Shape {

  public:
    Square(double side);

    const double getArea() {
      return m_side*m_side;
    }

    const double getPerimeter() {
      return 4*m_side;
    }

  private:
    const int m_side;
};
