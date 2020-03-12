#include "Triangle.h"

#include <cmath>
#include <sstream>

Triangle::Triangle(double h, double b)
    : Shape("triangle", 3),
      m_height(h),
      m_base(b) {
    /* nothing to do */
}

double Triangle::getPerimeter() const {
    return m_base + 2 * sqrt(m_height * m_height + (m_base * m_base / 4));
}

double Triangle::getArea() const {
    return m_height * m_base / 2;
}

std::string Triangle::print() const {
    std::ostringstream ss;
    ss << "[Triangle] base: "
       << m_base
       << " - height: "
       << m_height;
    return ss.str();
}

