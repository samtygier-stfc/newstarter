#include <cmath>
#include "Circle.h"

/** Creates an instance of a Circle 
 * @param radius The value of the radius of the circle
 */
Circle::Circle(double radius)
{
  m_radius = radius;
  m_type = "Circle";
  m_numSides = 1;
}

/** Calculates the area of a circle
 * @return Value of area
 */
double Circle::area() const
{
  return M_PI*pow(m_radius,2);
}

/** Calculates the perimeter of a circle
 * @return Value of perimeter
 */
double Circle::perimeter() const
{
  return M_PI*2.0*m_radius;
}

/** Creates a string from the members of Circle
 * @return String format of the data
 */
std::string Circle::toString() const
{
  return ("Type : Circle\n"
         "Number of Sides : 1\n"
         "Radius : " + std::to_string(m_radius) + "\n"
         "Area : " + std::to_string(area()) + "\n"
         "perimeter : " + std::to_string(perimeter()) + "\n");
}