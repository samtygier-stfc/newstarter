#include "Circle.h"
#include "Shape.h"
#include <math.h>

//constructor to initialise the circle if no arguments are given
Circle::Circle() 
		: Shape("Circle", 1), m_radius(0) {}

//constructor to initialise the circle of the required radius
Circle::Circle(double radius) 
		: Shape("Circle", 1), m_radius(radius) {}

//function to caluclate the perimeter of a circle and return value of type double
double Circle::perimeter() const { return M_PI * 2 * m_radius; }

//function to caluclate the area of a circle and return value of type double
double Circle::area() const { return M_PI * pow(m_radius, 2); }
