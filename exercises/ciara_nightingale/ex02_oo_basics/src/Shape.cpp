#include "Shape.h"

//construct a shape if no arguments are given with type Nul and zero sides
Shape::Shape() : m_type("Nul"), m_sides(0) {}

//construct a shape of the required type
Shape::Shape(std::string type, int sides) : m_type(type), m_sides(sides) {}

//function to obtain the type of the shape (read only)
std::string Shape::getType() const { return m_type; }

//function to obtain the number of sides (read only)
int Shape::getSides() const { return m_sides; }
