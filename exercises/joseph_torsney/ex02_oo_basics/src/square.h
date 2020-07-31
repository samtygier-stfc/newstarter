#pragma once

#include "shape.h"

class Square: public Shape {

  public:
    Square(double side);

    double getArea() const override;

    double getPerimeter() const override;

  private:
    const double m_side;
};
