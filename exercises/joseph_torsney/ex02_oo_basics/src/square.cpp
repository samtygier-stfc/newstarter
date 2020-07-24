#include "square.h"

Square::Square(double s) : Shape("square", 4), m_side(s) {};

double Square::getPerimeter() const {
  return 4*m_side;
}

double Square::getArea() const {
  return m_side*m_side;
}
