#include "rect.h"
#include "shape.h"

Rect::Rect(double a, double b) : Shape("rect", 4), m_side1(a), m_side2(b) {};

double Rect::getArea() {
  return (m_side1 * m_side2);
}

double Rect::getPerimeter() {
  return (2*m_side1 + 2*m_side2);
}
