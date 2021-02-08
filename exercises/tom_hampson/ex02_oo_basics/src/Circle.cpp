#include "Circle.h"

#include <cmath>

Circle::Circle(const double radius)
  : Shape(1, "circle"),
  m_radius(radius)
{
  calculateArea();
  calculatePerimeter();
}

void Circle::calculateArea()
{
  m_area = M_PI * m_radius * m_radius;
}

void Circle::calculatePerimeter()
{
  m_perimeter = 2.0 * M_PI * m_radius;
}
