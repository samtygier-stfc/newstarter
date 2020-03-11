#include "Rectangle.h"

#include <sstream>

Rectangle::Rectangle(double h, double w)
    : Shape("rectangle", 4),
      height(h),
      width(w) {
    /* nothing to do */
}

double Rectangle::getPerimeter(void) {
    return 2 * height + 2 * width;
}

double Rectangle::getArea(void) {
    return height * width;
}

std::string Rectangle::print(void) {
    std::ostringstream ss;
    ss << "[Rectangle] height: "
       << height
       << " - width: "
       << width;
    return ss.str();
}

