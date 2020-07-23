#include <string>
#include "shape.h"

Shape::Shape(std::string t, int s) : type(t), sides(s) {};

int Shape::getSides() {
  return sides;
}

std::string Shape::getType() {
  return type;
}

std::string Shape::toString() {
  return (
    "Type: " + type + 
    ", Sides: " + std::to_string(sides) + 
    ", Area: " + std::to_string(getArea()) + 
    ", Perimeter: " + std::to_string(getPerimeter())
  );
}
