#include <iostream>
#include <string>
#include "Square.h"

/** Creates an instance of a Square 
 * @param _lengthSides The value of the length of all the sides
 */
Square::Square(double _lengthSides)
{
  lengthSides = _lengthSides;
  type = "Square";
  numSides = 4;
}

/** Calculates the area of a square
 * @return Value of area
 */
double Square::area()
{
  return lengthSides*lengthSides;
}

/** Calculates the perimeter of a square
 * @return Value of perimeter
 */
double Square::perimeter()
{
  return lengthSides*4;
}