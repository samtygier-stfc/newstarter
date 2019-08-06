#include "Shape.h"

// Construct a shape if no arguments are given with type Nul and zero sides
Shape::Shape() : m_type("Nul"), m_sides(0) {}

/** Construct a shape of the required type
*
* @param type The type of shape 
* @param sides The number of sides
*/
Shape::Shape(std::string type, int sides) : m_type(type), m_sides(sides) {}

/** Obtain the type of the shape (read only)
*
* @return A string for the type of the shape
*
*/
std::string Shape::getType() const { return m_type; }

/** Obtain the number of sides (read only)
*
* @return an integer for the number of sides of the shape
*
*/
int Shape::getSides() const { return m_sides; }
