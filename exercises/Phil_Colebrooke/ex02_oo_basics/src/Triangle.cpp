#include "Triangle.h"

Triangle::Triangle(double height, double base)
    : Shape("Triangle", 3), m_height{height}, m_base{base} {}

/** Calculates the perimeter of the isoceles triangle
 *
 * @return The perimeter of the triangle
 *
 */
double Triangle::getPerimeter() {
  // perimeter is base + 2 * length of other side
  // uses pythagoras
  return m_base + (2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4)));
}

/** Calculates the area of the isoceles triangle
 *
 * @return The area of the triangle
 *
 */
double Triangle::getArea() {
  // area is base multiplied by height multiplied by a half
  return 0.5 * m_base * m_height;
}
