#include "Rectangle.h"

/** Constructs a rectangle using the arguments as the dimentions
* @param width The width of the rectangle
* @param height The height of the rectangle
*/
Rectangle::Rectangle(double width, double height)
    : Shape("Rectangle", 2), m_width(width), m_height(height) {}

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
