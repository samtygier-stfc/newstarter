#include "Rectangle.h"
#include "Shape.h"

Rectangle::Rectangle() 
		: Shape("Rectangle", 2), m_width(0), m_height(0) {}

Rectangle::Rectangle(double width, double height)
    : Shape("Rectangle", 2), m_width(width), m_height(height) {}

Rectangle::Rectangle(double width)
    : Shape("Square", 2), m_width(width), m_height(width) {}

double Rectangle::perimeter() const { return 2 * m_width + 2 * m_height; }

double Rectangle::area() const { return m_width * m_height; }
