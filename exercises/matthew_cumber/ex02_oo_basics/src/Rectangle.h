#pragma once

#include "Shape.h"

/*
 * Stores data for a rectangle shape
 * Inherits from class Shape
 * m_width : Stores the width of the rectangle
 * m_height : Stores the height of the rectangle
 */
class Rectangle : public Shape
{
public:
  /// Constructor of rectangle
  Rectangle(double width, double height);

  /// implementation of area, perimeter and to string for a rectangle (virtual in Shape class)
  double area() const override;
  double perimeter() const override;
  std::string toString() const override;

private:
  double m_width;
  double m_height;
};