#include "Circle.h"

#include <cmath>
#include <sstream>

Circle::Circle(double r)
    : Shape("circle", 1),
      m_radius(r) {
    /* nothing to do */
}

double Circle::getPerimeter() const{
    return 2 * M_PI * m_radius;
}

double Circle::getArea() const {
    return M_PI * m_radius * m_radius;
}

std::string Circle::print() const {
    std::ostringstream ss;
    ss << "[Circle] radius: "
       << m_radius;
    return ss.str();
}

