#include <iostream>
#include <string>
#include "Rectangle.h"

/** Creates an instance of a Rectangle 
 * @param _width The value of the  width of the rectangle
 * @param _height The value of the height of the rectangle
 */
Rectangle::Rectangle(double _width, double _height)
{
  width = _width;
  height = _height;
  type = "Rectangle";
  numSides = 4;
}

/** Calculates the area of a rectangle
 * @return Value of area
 */
double Rectangle::area()
{
  return width*height;
}

/** Calculates the perimeter of a rectangle
 * @return Value of perimeter
 */
double Rectangle::perimeter()
{
  return width*2 + height*2;
}