#include "Triangle.h"
#include<cmath>

double Triangle::calcArea() const {
	return 0.5*(m_base * m_height);
}

double Triangle::calcPerimiter() const {
	return m_base + 2*std::sqrt(std::pow(m_height,2) + std::pow(m_base/2,2));
}