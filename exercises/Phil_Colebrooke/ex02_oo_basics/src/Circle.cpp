#include "Circle.h"

Circle::Circle(double radius) : Shape("Circle", 1), m_radius{radius} {}

/** Calculates the circumference of the circle
 *
 * @return The circumference of the circle
 *
 */
double Circle::getPerimeter() const {
  // area is pi multiplied by diameter
  const double DIAMETER = m_radius * 2;

  return M_PI * DIAMETER;
}

/** Calculates the area of the circle
 *
 * @return The area of the circle
 *
 */
double Circle::getArea() const {
  // area is pi multiplied by radius squared
  return M_PI * m_radius * m_radius;
}
