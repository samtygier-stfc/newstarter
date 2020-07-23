#include "Square.h"
#include "Shape.cpp"

//Square constructor
Square::Square(double side1) {
  m_side1 = side1;
  Shape {side1*4, side1*side1, "Square", 4};
}

//Mutator methods
void Square::setSide1(double side1) {
  m_side1 = side1;
}