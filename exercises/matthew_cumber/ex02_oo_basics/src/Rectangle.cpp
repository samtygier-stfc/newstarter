#include "Rectangle.h"

/** Creates an instance of a Rectangle 
 * @param width The value of the  width of the rectangle
 * @param height The value of the height of the rectangle
 */
Rectangle::Rectangle(double width, double height)
{
  m_width = width;
  m_height = height;
  m_type = "Rectangle";
  m_numSides = 4;
}

/** Calculates the area of a rectangle
 * @return Value of area
 */
double Rectangle::area() const
{
  return m_width*m_height;
}

/** Calculates the perimeter of a rectangle
 * @return Value of perimeter
 */
double Rectangle::perimeter() const
{
  return m_width*2 + m_height*2;
}

/** Creates a string from the members of Rectangle
 * @return String format of the data
 */
std::string Rectangle::toString() const
{
  return ("Type : Rectangle\n"
         "Number of Sides : 4\n"
         "Width : " + std::to_string(m_width) + "\n"
         "Height : " + std::to_string(m_height) + "\n"
         "Area : " + std::to_string(area()) + "\n"
         "perimeter : " + std::to_string(perimeter()) + "\n");
}