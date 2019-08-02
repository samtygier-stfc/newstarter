#include "Triangle.h"
#include "Shape.h"
#include <cmath>

Triangle::Triangle():m_base(0), m_height(0){}

Triangle::Triangle(double base, double height): m_base(base), m_height(height){}

double Triangle::area() const {
		return m_base * m_height;
}

double Triangle::perimeter() const {
		return m_base + 2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4));
}
