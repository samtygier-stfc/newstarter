#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:
  Triangle(float _height, float _base);
  float area();
  float perimeter();

private:
  float height;
  float base;
};