#include "Triangle.h"
#include "Shape.h"
#include <math.h> 

//Triangle constructor
Triangle::Triangle(double height, double base) {
  m_height = height;
  m_base = base;
  Shape {calcPerimeter(height, base), (height*base/2), "Triangle", 3};
}

/** Calculate the perimeter of an isoceles triangle
 *  @param h height - the height of the triangle
 *  @param b base - the base of the triangle
 *  @return the perimeter of the triangle 
 */ 
double calcPerimeter(double h, double b) {
  double toSqrt = h*h + (b*h/4);
  return b + 2*(sqrt(toSqrt));
}

//Mutator methods
void Triangle::setBase(double base) {
  m_base = base;
}

void Triangle::setHeight(double height) {
  m_height = height;
}