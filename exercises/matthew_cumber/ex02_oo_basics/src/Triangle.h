#pragma once

#include "Shape.h"

/*
 * Stores data for a triangle shape
 * Inherits from class Shape
 * height : Stores the height of the triangle
 * base : Stores the length of the base of the triangle
 */
class Triangle : public Shape
{
public:
  /// Constructor of triangle
  Triangle(double height, double base);

  /// implementation of area, perimeter and to string for a triangle (virtual in Shape class)
  double area() const override;
  double perimeter() const override;
  std::string toString() const override;

private:
  double m_height;
  double m_base;
};