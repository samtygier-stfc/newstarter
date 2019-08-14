#include "Circle.h"
#include <math.h>

/** Constructor to initialise the circle of the required radius
*
* @param radius The radius of the circle
*
*/
Circle::Circle(double radius)
		: Shape("Circle", 1), m_radius(radius) {}

/** Caluclate the perimeter of a circle
*
* @return the perimeter as a double
*
*/
double Circle::perimeter() const { return M_PI * 2 * m_radius; }

/** Caluclate the area of a circle
*
* @return the area as a double
*
*/
double Circle::area() const { return M_PI * pow(m_radius, 2); }
