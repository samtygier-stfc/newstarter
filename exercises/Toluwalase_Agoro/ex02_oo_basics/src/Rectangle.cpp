#include "Rectangle.h"
#include "BaseShape.h"

double Rectangle::calculateArea() {
  if (m_area == 0.0) {
    m_area = m_length * m_width;

  }
  return m_area;
}

double Rectangle::calculatePerimeter() {
  if (m_perimeter == 0) {
    m_perimeter = 2 * (m_length + m_width);

  }
  return m_perimeter;
}