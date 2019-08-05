#include <math.h>
#include "Circle.h"

Circle::Circle(double radius) : ShapeBase(1, "Circle"), m_radius(radius){};

ShapeBase *Circle::clone() const {
  // clone function here
}

double Circle::calculatePerimeter() const { return 2 * M_PI * m_radius; }
double Circle::calculateArea() const { return M_PI * pow(m_radius, 2); }