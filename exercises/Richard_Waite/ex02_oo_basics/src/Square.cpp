#include "Square.h"

double Square::calcArea() const {
	return m_side * m_side;
}

double Square::calcPerimiter() const {
	double nsides = getNsides(); // this function returns an int...
	return nsides * m_side;
}