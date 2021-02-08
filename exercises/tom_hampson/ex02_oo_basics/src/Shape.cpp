#include "Shape.h"

#include <iostream>

Shape::Shape(const int nSides, const std::string& shapeType)
  : m_nSides(nSides),
  m_shapeType(shapeType),
  m_area(0.0),
  m_perimeter(0.0)
{
}

void Shape::print() const
{
  std::cout << m_shapeType
    << ": nSides = " << m_nSides
    << ", perimeter = " << m_perimeter
    << ", area = " << m_area
    << std::endl;
}
