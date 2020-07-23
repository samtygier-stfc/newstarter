#include "rect.h"
#include "shape.h"

Rect::Rect(double a, double b) : Shape("rect", 4), side1(a), side2(b) {};

double Rect::getArea() {
  return (side1 * side2);
}

double Rect::getPerimeter() {
  return (2*side1 + 2*side2);
}
