#include "Square.h"

#include <sstream>

Square::Square(double s)
    : Shape("square", 4),
      m_size(s) {
    /* nothing to do */
}

double Square::getPerimeter() const {
    return 4 * m_size;
}

double Square::getArea() const {
    return m_size * m_size;
}

std::string Square::print() const {
    std::ostringstream ss;
    ss << "[Square] side length: "
       << m_size;
    return ss.str();
}

