#include "Circle.h"

#include <cmath>

Circle::Circle(double r)
    : Shape("circle", 1),
      radius(r) {
    /* nothing to do */
}

double Circle::getPerimeter(void) {
    return 2 * M_PI * radius;
}

double Circle::getArea(void) {
    return M_PI * radius * radius;
}

