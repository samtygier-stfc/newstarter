#include "Square.h"

#include <sstream>

Square::Square(double s)
    : Shape("square", 4),
      size(s) {
    /* nothing to do */
}

double Square::getPerimeter(void) {
    return 4 * size;
}

double Square::getArea(void) {
    return size * size;
}

std::string Square::print(void) {
    std::ostringstream ss;
    ss << "[Square] side length: "
       << size;
    return ss.str();
}

