#include "Rectangle.h"

/** Constructs Rectangle object
 *
 * @param length: rectangle length
 * @param width: rectangle width
 *
 */
Rectangle::Rectangle(double length, double width)
    : ShapeBase(4, "Rectangle"), m_length(length), m_width(width){};

/** Calculates rectangle perimeter
 *
 * @return perimeter
 *
 */
double Rectangle::getPerimeter() const { return 2 * m_length + 2 * m_width; }

/** Calculates rectangle area
 *
 * @return area
 *
 */
double Rectangle::getArea() const { return m_length * m_width; }

/** Retrieves rectangle length member variable
 *
 * @return m_length: length member variable
 *
 */
double Rectangle::getLength() const { return m_length; }

/** Retrieves rectangle width member variable
 *
 * @return m_width: width member variable
 *
 */
double Rectangle::getWidth() const { return m_width; }