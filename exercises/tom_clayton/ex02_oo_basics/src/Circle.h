#pragma once
#include "Shape.h"

class Circle : public Shape
{
  private: 
    double m_radius;

  public:
    Circle(double radius);

    // Implementation of Shape virtual functions
    double calcPerimeter() override;

    double calcArea() override;

    // Accessor/mutator methods
    double getRadius();

    void setRadius(double radius);
};