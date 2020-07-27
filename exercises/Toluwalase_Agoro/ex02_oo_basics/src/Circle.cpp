#include "Circle.h"


double Circle::calculateArea() {
  if (m_area == 0) {
    m_area = (pi * m_radius*m_radius);

  }
  return m_area;
}


double Circle::calculatePerimeter() {
  if (m_perimeter == 0) {
    m_perimeter = ( 2*pi*m_radius);

  }
  return m_perimeter;
}