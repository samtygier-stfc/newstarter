#include "Triangle.h"
#include "Shape.h"
#include <cmath>

//construct the triangle withdimentions set to zero if no arguments are given
Triangle::Triangle() 
		: Shape("Triangle", 3), m_base(0), m_height(0) {}

//construct the triangle with the gievn dimentions
Triangle::Triangle(double base, double height)
    : Shape("Triangle", 3), m_base(base), m_height(height) {}

//caluclate the area of the triangle and return value as a double
double Triangle::area() const { return m_base * m_height; }

//calculate the perimeter of the triangle and return value as a double
double Triangle::perimeter() const {
  return m_base + 2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4));
}
