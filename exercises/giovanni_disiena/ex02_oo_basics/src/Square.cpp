#include "Square.h"

/** Constructs Square object
 *
 * @param length: square length
 *
 */
Square::Square(double length)
    : ShapeBase(4, "Square"), m_length(length) {}

/** Calculates square perimeter
 *
 * @return perimeter
 *
 */
double Square::getPerimeter() const { return 4 * m_length; }

/** Calculates square area
 *
 * @return area
 *
 */
double Square::getArea() const { return m_length * m_length; }

/** Retrieves square length member variable
 *
 * @return m_length: length member variable
 *
 */
double Square::getLength() const { return m_length; }