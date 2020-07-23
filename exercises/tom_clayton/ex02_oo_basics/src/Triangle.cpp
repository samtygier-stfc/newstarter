#include "Triangle.h"
#include <math.h> 

//Triangle constructor
Triangle::Triangle(double height, double base) {
  m_height = height;
  m_base = base;
  m_perimeter = calcPerimeter(height, base);
  m_area = calcArea(height, base);
  m_sides = 3;
  m_type = "Triangle";
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

/** Calculate the area of an isoceles triangle
 *  @param h height - the height of the triangle
 *  @param b base - the base of the triangle
 *  @return the area of the triangle 
 */ 
double calcArea(double h, double b) {
  return h*b/2;
}

//Mutator methods
void Triangle::setBase(double base) {
  m_base = base;
}

void Triangle::setHeight(double height) {
  m_height = height;
}