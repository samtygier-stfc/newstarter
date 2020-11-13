#include <cmath>

#include "triangle.h"

std::string Triangle::getType() const {
	return "triangle";
}

signed int Triangle::getSides() const {
	return 3;
}

double Triangle::getPerimeter() const {
	return m_base + 2 * sqrt(m_height*m_height + m_base*m_base/4);
}

double Triangle::getArea() const {
	return 0.5 * m_height * m_base;
}
