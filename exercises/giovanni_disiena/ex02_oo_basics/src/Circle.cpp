#include "Circle.h"

Circle::Circle(double radius) : ShapeBase(1, "Circle"), m_radius(radius){};

ShapeBase *Circle::clone() const { return new Circle(*this); }

double Circle::getPerimeter() const { return 2 * M_PI * m_radius; }
double Circle::getArea() const { return M_PI * pow(m_radius, 2); }

double Circle::getRadius() const { return m_radius; }
