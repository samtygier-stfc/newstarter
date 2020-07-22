#include <iostream>
#include <string>
#include <cmath>
#include "Circle.h"

/** Creates an instance of a Circle 
 * @param _radius The value of the radius of the circle
 */
Circle::Circle(float _radius)
{
  radius = _radius;
  type = "Circle";
  numSides = 1;
}

/** Calculates the area of a circle
 * @return Value of area
 */
float Circle::area()
{
  return M_PI*pow(radius,2);
}

/** Calculates the perimeter of a circle
 * @return Value of perimeter
 */
float Circle::perimeter()
{
  return M_PI*2.0*radius;
}