#include "Shape.h"

Shape::Shape(std::string t, int n)
    : m_type(t),
      m_numberOfSides(n) {
    /* nothing to do */
}

Shape::~Shape() {
    /* nothing to do */
}

std::string Shape::getType() const {
    return m_type;
}

int Shape::getSides() const {
    return m_numberOfSides;
}

