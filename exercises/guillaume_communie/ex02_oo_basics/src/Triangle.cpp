#include "Triangle.h"

#include <cmath>

Triangle::Triangle(double h, double b)
    : Shape("triangle", 3),
      height(h),
      base(b) {
    /* nothing to do */
}

double Triangle::getPerimeter(void) {
    return base + 2 * sqrt(height * height + (base * base / 4));
}

double Triangle::getArea(void) {
    return height * base / 2;
}

