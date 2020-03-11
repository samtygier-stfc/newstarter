#include "Square.h"

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

