#include "Rectangle.h"

Rectangle::Rectangle(double length, double width)
    : ShapeBase(4, "Rectangle"), m_length(length), m_width(width){};

Rectangle::Rectangle(double length)
    : ShapeBase(4, "Square"), m_length(length), m_width(length){};

double Rectangle::getPerimeter() const {
  return 2*m_length + 2*m_width;
}
double Rectangle::getArea() const { return m_length * m_width; }

double Rectangle::getLength() const { return m_length; }

double Rectangle::getWidth() const { return m_width; }
