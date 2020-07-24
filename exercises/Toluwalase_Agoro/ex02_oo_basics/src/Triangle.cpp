#pragma once
#include "Triangle.h"
#include "BaseShape.h"


double Triangle::calculateArea() {
  if (m_area == 0) {
    m_area = (0.5 * m_base * m_height);

  }
  return m_area;
}

double Triangle::calculatePerimeter() {
  if (m_perimeter == 0) {
    m_perimeter = (m_base + 2 * std::sqrt((m_height * m_height) + (m_base * m_base) * 0.25));

  }
  return m_perimeter;
}