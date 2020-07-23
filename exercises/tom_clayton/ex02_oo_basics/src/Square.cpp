#include "Square.h"

//Square constructor
Square::Square(double side1) {
  m_side1 = side1;
  m_type = "Square";
  m_area = side1*side1;
  m_perimeter = side1*4;
  m_sides = 4;
}

//Mutator methods
void Square::setSide1(double side1) {
  m_side1 = side1;
}