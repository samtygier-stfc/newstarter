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

const std::string& Shape::shapeType() const
{
    return m_shapeType;
}

int Shape::nSides() const
{
  return m_nSides;
}

double Shape::area() const
{
  return m_area;
}

double Shape::perimeter() const
{
  return m_perimeter;
}
