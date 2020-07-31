#include "Rectangle.h"

//Rectangle constructor
Rectangle::Rectangle(double side1, double side2) : Shape("Rectangle", 4) {
  m_side1 = side1;
  m_side2 = side2;
  Shape::setPerimeter(calcPerimeter());
  Shape::setArea(calcArea());
}

// Implementation of Shape virtual functions
double Rectangle::calcPerimeter() {
  double side1 = getSide1();
  double side2 = getSide2();
  return 2*(side1+side2);
}

double Rectangle::calcArea() {
  double side1 = getSide1();
  double side2 = getSide2();
  return side1*side2;
}

// Accessor/mutator methods
double Rectangle::getSide1() {
  return m_side1;
}

double Rectangle::getSide2() {
  return m_side1;
}

void Rectangle::setSide1(double side1) {
  m_side1 = side1;
}

void Rectangle::setSide2(double side2) {
  m_side2 = side2;
}