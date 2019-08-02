#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle() :m_width(0), m_height(0){}
Rectangle::Rectangle(double width, double height) :m_width(width), m_height(height){}
double Rectangle::perimeter() const {
		return 2 * m_width + 2 * m_height;
}
double Rectangle::area() const {
		return m_width * m_height;
}