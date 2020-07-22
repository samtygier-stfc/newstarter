#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
  Circle(float _radius);
  float area();
  float perimeter();

private:
  float radius;
};