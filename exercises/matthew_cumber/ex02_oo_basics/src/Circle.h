#pragma once

#include "Shape.h"

/*
 * Stores data for a circle shape
 * Inherits from class Shape
 * m_radius : Stores the radius of the circle
 */
class Circle : public Shape
{
public:
  /// Constructor of circle
  Circle(double radius);

  /// implementation of area, perimeter and to string for a circle (virtual in Shape class)
  double area() const override;
  double perimeter() const override;
  std::string toString() const override;

private:
  double m_radius;
};