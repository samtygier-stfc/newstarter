#pragma once

#include "Shape.h"

/*
 * Stores data for a rectangle shape
 * Inherits from class Shape
 * width : Stores the width of the rectangle
 * height : Stores the height of the rectangle
 */
class Rectangle : public Shape
{
public:
  /// Constructor of rectangle
  Rectangle(float _width, float _height);

  /// implementation of area and perimeter for a rectangle (virtual in Shape class)
  float area();
  float perimeter();

private:
  float width;
  float height;
};