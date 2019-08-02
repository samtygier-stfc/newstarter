#include "Circle.h"
#include <math.h>
#include "Shape.h"

Circle::Circle() :m_radius(0) {}

Circle::Circle(double radius) :m_radius(radius) {}

double Circle::perimeter() const {
		return M_PI * 2 * m_radius;
}
double Circle::area() const {
		return M_PI * pow(m_radius, 2);
}