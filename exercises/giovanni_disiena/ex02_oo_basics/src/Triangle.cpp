#include "Triangle.h"

Triangle::Triangle(double base, double height) : ShapeBase(3, "Triangle"), m_base(base), m_height(height){};

ShapeBase *Triangle::clone() const { return new Triangle(*this); }

double Triangle::calculatePerimeter() const { return m_base+2*sqrt(pow(m_height, 2) + pow(m_base, 2)*0.25); }
double Triangle::calculateArea() const { return 0.5*m_base*m_height; }