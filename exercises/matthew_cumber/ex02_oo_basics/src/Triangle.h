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
  Triangle(float _height, float _base);

  /// implementation of area and perimeter for a triangle (virtual in Shape class)
  float area();
  float perimeter();

private:
  float height;
  float base;
};