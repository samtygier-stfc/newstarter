#include <cmath>
#include "circle.h"
#include "shape.h"

Circle::Circle(double r) : Shape("circle", 1), m_radius(r) {};

const double Circle::getArea()  {
  return M_PI*pow(m_radius, 2);
}

const double Circle::getPerimeter() {
  return 2*M_PI*m_radius;
}
