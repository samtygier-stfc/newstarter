#include "Rectangle.h"
#include "Shape.cpp"

//Rectangle constructor
Rectangle::Rectangle(double side1, double side2) {
  m_side1 = side1;
  m_side2 = side2;
  Shape {(2*(side1+side2)), side1*side2, "Rectangle", 4};
}

//Mutator methods
void Rectangle::setSide1(double side1) {
  m_side1 = side1;
}

void Rectangle::setSide2(double side2) {
  m_side2 = side2;
}