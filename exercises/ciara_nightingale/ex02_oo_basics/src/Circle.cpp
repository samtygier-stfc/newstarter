#include "Circle.h"
#include "Shape.h"
#include <math.h>

Circle::Circle() 
		: Shape("Circle", 1), m_radius(0) {}

Circle::Circle(double radius) 
		: Shape("Circle", 1), m_radius(radius) {}

double Circle::perimeter() const { return M_PI * 2 * m_radius; }

double Circle::area() const { return M_PI * pow(m_radius, 2); }
