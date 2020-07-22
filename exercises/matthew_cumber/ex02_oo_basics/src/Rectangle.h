#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
  Rectangle(float _width, float _height);
  float area();
  float perimeter();

private:
  float width;
  float height;
};