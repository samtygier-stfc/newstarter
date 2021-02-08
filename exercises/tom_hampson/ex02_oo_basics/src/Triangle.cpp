#include "Triangle.h"

#include <cmath>

Triangle::Triangle(const double height, const double base)
  : Shape(3, "triangle"),
  m_height(height),
  m_base(base)
{
  calculateArea();
  calculatePerimeter();
}

void Triangle::calculateArea()
{
  m_area = 0.5 * m_base * m_height;
}

void Triangle::calculatePerimeter()
{
  m_perimeter = m_base + 2.0 * sqrt(m_height * m_height + 0.25 * m_base * m_base);
}
