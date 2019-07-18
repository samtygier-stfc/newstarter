#include "Square.h"

Square::Square(double sideLength)
    : Shape("Square", 4), m_sideLength{sideLength} {}

/** Calculates the perimeter of the square
 *
 * @return The perimeter of the square
 *
 */
double Square::getPerimeter() const {
  // the perimeter is the side length multiplied by 4
  const int NUMBER_OF_SIDES = 4;
  return m_sideLength * NUMBER_OF_SIDES;
}

/** Calculates the area of the square
 *
 * @return The area of the square
 *
 */
double Square::getArea() const {
  // area is the side length squared
  return m_sideLength * m_sideLength;
}
