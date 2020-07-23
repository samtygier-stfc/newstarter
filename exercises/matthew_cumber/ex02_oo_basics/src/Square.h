#pragma once

#include "Shape.h"

/*
 * Stores data for a square shape
 * Inherits from class Shape
 * lengthSides : Stores the length of each side of the square
 */
class Square : public Shape
{
public:
  /// Constructor of triangle
  Square(double lengthSides);

  /// implementation of area, perimeter and to string for a square (virtual in Shape class)
  double area() const override;
  double perimeter() const override;
  std::string toString() const override;

private:
  double m_lengthSides;
};