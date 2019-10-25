#include "Rectangle.h"

double Rectangle::calcArea() const {
	return m_width * m_height;
}

double Rectangle::calcPerimiter() const {
	return 2*m_width + 2*m_height;
}