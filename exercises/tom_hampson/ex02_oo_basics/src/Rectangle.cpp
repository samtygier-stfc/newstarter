#include "Rectangle.h"

Rectangle::Rectangle(const double side1, const double side2, const std::string& shapeType)
  : Shape(4, shapeType),
  m_side1(side1),
  m_side2(side2)
{
  calculateArea();
  calculatePerimeter();
}

void Rectangle::calculateArea()
{
  m_area = m_side1 * m_side2;
}

void Rectangle::calculatePerimeter()
{
  m_perimeter = 2.0 * m_side1 + 2.0 * m_side2;
}
