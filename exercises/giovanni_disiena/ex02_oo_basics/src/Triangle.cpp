#include "Triangle.h"

/** Constructs Triangle object
 *
 * @param base: triangle base length
 * @param height: triangle height
 *
 */
Triangle::Triangle(double base, double height)
    : ShapeBase(3, "Triangle"), m_base(base), m_height(height){};

/** Calculates triangle perimeter
 *
 * @return perimeter
 *
 */
double Triangle::getPerimeter() const {
  return m_base + 2 * sqrt(pow(m_height, 2) + pow(m_base, 2) * 0.25);
}

/** Calculates triangle area
 *
 * @return area
 *
 */
double Triangle::getArea() const { return 0.5 * m_base * m_height; }

/** Retrieves triangle base length member variable
 *
 * @return m_base: base member variable
 *
 */
double Triangle::getBase() const { return m_base; }

/** Retrieves triangle height member variable
 *
 * @return m_height: height member variable
 *
 */
double Triangle::getHeight() const { return m_height; }
