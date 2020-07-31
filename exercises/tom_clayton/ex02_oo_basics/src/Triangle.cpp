#include "Triangle.h"
#include <math.h> 

//Triangle constructor
Triangle::Triangle(double height, double base) : Shape("Triangle", 3){
  m_height = height;
  m_base = base;
  Shape::setPerimeter(calcPerimeter());
  Shape::setArea(calcArea());
}

/** Calculate the perimeter of an isoceles triangle
 *  @return the perimeter of the triangle 
 */ 
double Triangle::calcPerimeter() {
  double h = getHeight();
  double b = getBase();
  double toSqrt = h*h + (b*h/4);
  return b + 2*(sqrt(toSqrt));
}

/** Calculate the area of an isoceles triangle
 *  @return the area of the triangle 
 */ 
double Triangle::calcArea() {
  double h = getHeight();
  double b = getBase();
  return h*b/2;
}

// Accessor/mutator methods
double Triangle::getBase() {
  return m_base;
}

double Triangle::getHeight() {
  return m_height;
}

void Triangle::setBase(double base) {
  m_base = base;
}

void Triangle::setHeight(double height) {
  m_height = height;
}