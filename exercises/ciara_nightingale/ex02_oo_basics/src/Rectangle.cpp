#include "Rectangle.h"
#include "Shape.h"

// Construct a 0x0 rectangle to avoid errors if no arguments are given
Rectangle::Rectangle() 
		: Shape("Rectangle", 2), m_width(0), m_height(0) {}

/** Constructs a rectangle using the arguments as the dimentions
* @param width The width of the rectangle
* @param height The height of the rectangle
*/
Rectangle::Rectangle(double width, double height)
    : Shape("Rectangle", 2), m_width(width), m_height(height) {}

/** Constructs a square if only one argument is given
*
* @param width The side length of a square
*
*/
Rectangle::Rectangle(double width)
    : Shape("Square", 2), m_width(width), m_height(width) {}

/** Calculates the perimeter 
*
* @return The value of the perimeter as a double
*
*/
double Rectangle::perimeter() const { return 2 * m_width + 2 * m_height; }

/** Calculates the area
*
* @return The value of the area as a double
*
*/
double Rectangle::area() const { return m_width * m_height; }
