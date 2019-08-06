#include "Circle.h"
#include <math.h>

Circle::Circle(double radius) : ShapeBase(1, "Circle"), m_radius(radius){};

ShapeBase *Circle::clone() const { return new Circle(*this); }

double Circle::calculatePerimeter() const { return 2 * M_PI * m_radius; }
double Circle::calculateArea() const { return M_PI * pow(m_radius, 2); }