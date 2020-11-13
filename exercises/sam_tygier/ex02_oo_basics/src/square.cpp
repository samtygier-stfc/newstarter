#include "square.h"

std::string Square::getType() const {
	return "square";
}

signed int Square::getSides() const {
	return 4;
}

double Square::getPerimeter() const {
	return 4 * m_side1;
}

double Square::getArea() const {
	return m_side1 * m_side1;
}
