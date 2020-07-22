#pragma once

#include "Shape.h"

class Square : public Shape
{
public:
  Square(float _lengthSides);
  float area();
  float perimeter();

private:
  float lengthSides;
};