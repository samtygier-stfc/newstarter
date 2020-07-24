#pragma once 
#include "Square.h"
#include "BaseShape.h"


double Square::calculateArea() {
  if (m_area == 0.0) {
    m_area = m_length * m_length;

  }
  return m_area;
}

double Square::calculatePerimeter() {
  if (m_perimeter == 0.0) {
    m_perimeter = 4 * m_length;

  }
  return m_perimeter;
}
