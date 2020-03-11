#include "Shape.h"

Shape::Shape(std::string t, int n)
    : type(t),
      numberOfSides(n) {
    /* nothing to do */
}

std::string Shape::getType(void) {
    return type;
}

int Shape::getSides(void) {
    return numberOfSides;
}

