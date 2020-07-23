#include "Circle.h"
#include <cmath>

const double PI = 2 * acos(0.0);

//Circle constructor
Circle::Circle(double radius) {
  m_radius = radius;
  m_perimeter = (2*PI*radius);
  m_area = (PI*radius*radius);
  m_type = "Circle";
  m_sides = 0;
}

//Mutator methods
void Circle::setRadius(double radius) {
  m_radius = radius;
}
