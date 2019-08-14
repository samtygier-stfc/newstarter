#include "Square.h"

/** Constructs a square using the arguments as the dimentions
* @param sideLength The side length of the square
*/
Square::Square(double sideLength)
    : Shape("Square", 2), m_sideLength(sideLength) {}

/** Calculates the perimeter
*
* @return The value of the perimeter as a double
*
*/
double Square::perimeter() const { return 4 * m_sideLength; }

/** Calculates the area
*
* @return The value of the area as a double
*
*/
double Square::area() const { return 2 * m_sideLength; }