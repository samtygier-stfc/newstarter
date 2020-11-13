#include "rectangle.h"

std::string Rectangle::getType() const {
	return "rectangle";
}

signed int Rectangle::getSides() const {
	return 4;
}

double Rectangle::getPerimeter() const {
	return 2 * (m_side1 + m_side2);
}

double Rectangle::getArea() const {
	return m_side1 * m_side2;
}
