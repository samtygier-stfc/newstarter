#include <cmath>
#include "circle.h"
#include "shape.h"

Circle::Circle(double r) : Shape("circle", 1), m_radius(r) {};

double Circle::getArea() const {
  return M_PI*pow(m_radius, 2);
}

double Circle::getPerimeter() const {
  return 2*M_PI*m_radius;
}
