#include "Square.h"

//Square constructor
Square::Square(double side1) : Shape("Square", 4) {
  m_side1 = side1;
  Shape::setPerimeter(calcPerimeter());
  Shape::setArea(calcArea());
}

// Implementation of Shape virtual functions
double Square::calcPerimeter() {
  double side1 = getSide1();
  return side1*4;
}

double Square::calcArea() {
  double side1 = getSide1();
  return side1*side1;
}

// Accessor/mutator methods
double Square::getSide1() {
  return m_side1;
}

void Square::setSide1(double side1) {
  m_side1 = side1;
}