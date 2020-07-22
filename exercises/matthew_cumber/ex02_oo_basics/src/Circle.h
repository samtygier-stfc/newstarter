#pragma once

#include "Shape.h"

/*
 * Stores data for a circle shape
 * Inherits from class Shape
 * radius : Stores the radius of the circle
 */
class Circle : public Shape
{
public:
  /// Constructor of circle
  Circle(double _radius);

  /// implementation of area and perimeter for a circle (virtual in Shape class)
  double area();
  double perimeter();

private:
  double radius;
};