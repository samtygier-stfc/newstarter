#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
  private: 
    double m_side1;
    double m_side2;

  public:
    Rectangle(double side1, double side2);

    // Implementation of Shape virtual functions
    double calcPerimeter() override;

    double calcArea() override;

    // Accessor/mutator methods
    void setSide1(double side1);

    void setSide2(double side2);

    double getSide1();

    double getSide2();
};
