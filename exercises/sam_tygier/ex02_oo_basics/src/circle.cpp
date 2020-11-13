#include <cmath>

#include "circle.h"

std::string Circle::getType() const {
	return "circle";
}

signed int Circle::getSides() const {
	return 1;
}

double Circle::getPerimeter() const {
	return 2 * M_PI * m_radius;
}

double Circle::getArea() const {
	return M_PI * m_radius * m_radius;
}
