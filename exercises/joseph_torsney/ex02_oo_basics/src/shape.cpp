#include <string>
#include "shape.h"

Shape::Shape(std::string t, int s) : m_type(t), m_sides(s) {};

int Shape::getSides() {
  return m_sides;
}

std::string Shape::getType() {
  return m_type;
}

std::string Shape::toString() {
  return (
    "Type: " + m_type + 
    ", Sides: " + std::to_string(m_sides) + 
    ", Area: " + std::to_string(getArea()) + 
    ", Perimeter: " + std::to_string(getPerimeter())
  );
}
