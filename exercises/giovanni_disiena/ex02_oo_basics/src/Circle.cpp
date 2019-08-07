#include "Circle.h"

/** Constructs Circle object
 *
 * @param radius: circle radius
 *
 */
Circle::Circle(double radius) : ShapeBase(1, "Circle"), m_radius(radius){};

/** Calculates circle perimeter
 *
 * @return perimeter
 *
 */
double Circle::getPerimeter() const { return 2 * M_PI * m_radius; }

/** Calculates circle area
 *
 * @return area
 *
 */
double Circle::getArea() const { return M_PI * pow(m_radius, 2); }

/** Retrieves circle radius member variable
 *
 * @return m_radius: radius member variable
 *
 */
double Circle::getRadius() const { return m_radius; }