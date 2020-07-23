#include "Square.h"

/** Creates an instance of a Square 
 * @param lengthSides The value of the length of all the sides
 */
Square::Square(double lengthSides)
{
  m_lengthSides = lengthSides;
  m_type = "Square";
  m_numSides = 4;
}

/** Calculates the area of a square
 * @return Value of area
 */
double Square::area() const
{
  return m_lengthSides*m_lengthSides;
}

/** Calculates the perimeter of a square
 * @return Value of perimeter
 */
double Square::perimeter() const
{
  return m_lengthSides*4;
}

/** Creates a string from the members of Square
 * @return String format of the data
 */
std::string Square::toString() const
{
  return ("Type : Square\n"
         "Number of Sides : 4\n"
         "Length of Sides : " + std::to_string(m_lengthSides) + "\n"
         "Area : " + std::to_string(area()) + "\n"
         "perimeter : " + std::to_string(perimeter()) + "\n");
}