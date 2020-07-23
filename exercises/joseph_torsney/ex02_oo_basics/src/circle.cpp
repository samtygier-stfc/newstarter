#include <math.h>
#include "circle.h"
#include "shape.h"

Circle::Circle(double r) : Shape("circle", 1), radius(r) {};

double Circle::getArea()  {
  return M_PI*pow(radius, 2);
}

double Circle::getPerimeter() {
  return 2*M_PI*radius;
}
