#include "Circle.h"
#include<cmath>

const double PI = 4*std::atan(1);

double Circle::calcArea() const {
	return PI * std::pow(m_radius, 2);
}

double Circle::calcPerimiter() const {
	return 2 * PI * m_radius;
}