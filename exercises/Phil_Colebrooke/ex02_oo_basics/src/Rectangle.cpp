#include "Rectangle.h"

Rectangle::Rectangle(double length, double width)
    : Shape("Rectangle", 4), m_length{length}, m_width{width} {}

/** Calculates the perimeter of the rectangle
 *
 * @return The perimeter of the rectangle
 *
 */
double Rectangle::getPerimeter() const {
  // perimeter is the sum of each side multiplied by 2
  return (m_length * 2) + (m_width * 2);
}

/** Calculates the area of the rectangle
 *
 * @return The area of the rectangle
 *
 */
double Rectangle::getArea() const {
  // area is length multiplied by width
  return m_length * m_width;
}
