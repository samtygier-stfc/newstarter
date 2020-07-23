#include <cmath>
#include "Triangle.h"

/** Creates an instance of a Triangle 
 * @param height Value of the height of the triangle
 * @param base Value of the base of the triangle 
 */
Triangle::Triangle(double height, double base)
{
  m_height = height;
  m_base = base;
  m_type = "Triangle";
  m_numSides = 3;
}

/** Calculates the area of a triangle
 * @return Value of area
 */
double Triangle::area() const
{
  return (m_height*m_base)/2.0;
}

/** Calculates the perimeter of a triangle
 * @return Value of perimeter
 */
double Triangle::perimeter() const
{
  const double baseSquaredOverFour = pow(m_base,2)/4.0;
  const double root = sqrt(pow(m_height,2) + baseSquaredOverFour);
  return m_base + 2.0*root;
}

/** Creates a string from the members of Triangle
 * @return String format of the data
 */
std::string Triangle::toString() const
{
  return ("Type : Triangle\n"
         "Number of Sides : 3\n"
         "Base : " + std::to_string(m_base) + "\n"
         "Height : " + std::to_string(m_height) + "\n"
         "Area : " + std::to_string(area()) + "\n"
         "perimeter : " + std::to_string(perimeter()) + "\n");
}