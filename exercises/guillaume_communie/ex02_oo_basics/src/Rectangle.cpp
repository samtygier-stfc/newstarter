#include "Rectangle.h"

#include <sstream>

Rectangle::Rectangle(double h, double w)
    : Shape("rectangle", 4),
      m_height(h),
      m_width(w) {
    /* nothing to do */
}

double Rectangle::getPerimeter() const {
    return 2 * m_height + 2 * m_width;
}

double Rectangle::getArea() const {
    return m_height * m_width;
}

std::string Rectangle::print() const {
    std::ostringstream ss;
    ss << "[Rectangle] height: "
       << m_height
       << " - width: "
       << m_width;
    return ss.str();
}

