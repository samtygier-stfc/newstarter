#include "Circle.h"
#include <cmath>

const double PI = 2 * acos(0.0);

//Circle constructor
Circle::Circle(double radius) {
  m_radius = radius;
  Shape::setPerimeter(calcPerimeter());
  Shape::setArea(calcArea());
  Shape::setType("Circle");
  Shape::setSides(0);
}


// Implementation of Shape virtual functions
double Circle::calcPerimeter() {
  double r = getRadius();
  return 2*PI*r;
}

double Circle::calcArea() {
  double r = getRadius();
  return PI*r*r;
}

// Accessor/mutator methods
double Circle::getRadius() {
  return m_radius;
}

void Circle::setRadius(double radius) {
  m_radius = radius;
}
