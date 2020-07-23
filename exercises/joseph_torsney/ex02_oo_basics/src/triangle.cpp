#include "math.h"
#include "triangle.h"
#include "shape.h"

Triangle::Triangle(double b, double h) : Shape("triangle", 3), base(b), height(h) {};

double Triangle::getArea() {
  return 0.5 * base * height;
}

double Triangle::getPerimeter() {
  return base + 2*sqrt(pow(height, 2) + (pow(base, 2) / 4));
}
