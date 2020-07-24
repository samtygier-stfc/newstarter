#pragma once
#include "Shape.h"

class Triangle : public Shape
{
  private: 
    double m_height;
    double m_base;

  public:
    Triangle(double height, double base);

    // Implementation of Shape virtual functions
    double calcArea() override;
    
    double calcPerimeter() override;

    // Accessor/mutator methods
    double getBase();

    double getHeight();

    void setBase(double base);

    void setHeight(double height);
};
