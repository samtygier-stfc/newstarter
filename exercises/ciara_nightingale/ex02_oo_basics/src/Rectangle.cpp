#include "Rectangle.h"
#include "Shape.h"

//construct a 0x0 rectangle to avoid errors if no arguments are given
Rectangle::Rectangle() 
		: Shape("Rectangle", 2), m_width(0), m_height(0) {}

//constructs a rectangle using the arguments as the dimentions 
Rectangle::Rectangle(double width, double height)
    : Shape("Rectangle", 2), m_width(width), m_height(height) {}

//constructs a square if only one argument is given
Rectangle::Rectangle(double width)
    : Shape("Square", 2), m_width(width), m_height(width) {}

//calculates the perimeter and returns the value
double Rectangle::perimeter() const { return 2 * m_width + 2 * m_height; }

//calulates the area and returns the value
double Rectangle::area() const { return m_width * m_height; }
