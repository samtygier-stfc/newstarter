#include "Circle.h"
#include "Shape.cpp"
#include <cmath>

const double PI = 2 * acos(0.0);

//Circle constructor
Circle::Circle(double radius) {
  m_radius = radius;
  Shape {(2*PI*radius), (PI*radius*radius), "Circle", 0};
}

//Mutator methods
void Circle::setRadius(double radius) {
  m_radius = radius;
}
