#include "math.h"
#include "triangle.h"
#include "shape.h"

Triangle::Triangle(double b, double h) : Shape("triangle", 3), m_base(b), m_height(h) {};

double Triangle::getArea() const {
  return 0.5 * m_base * m_height;
}

double Triangle::getPerimeter() const {
  return m_base + 2*sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4));
}
