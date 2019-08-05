#include "Shape.h"

Shape::Shape() : m_type(0), m_sides(0) {}

Shape::Shape(std::string type, int sides) : m_type(type), m_sides(sides) {}

std::string Shape::getType() const { return m_type; }

int Shape::getSides() const { return m_sides; }
