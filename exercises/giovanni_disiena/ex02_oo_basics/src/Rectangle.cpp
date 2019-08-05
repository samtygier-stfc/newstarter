#include "Rectangle.h"

Rectangle::Rectangle(double length, double width)
    : ShapeBase(4, "Rectangle"), m_length(length), m_width(width){};

ShapeBase *Rectangle::clone() const {
  // clone function here
}

double Rectangle::calculatePerimeter() const {
  return 2*m_length + 2*m_width;
}
double Rectangle::calculateArea() const { return m_length * m_width; }