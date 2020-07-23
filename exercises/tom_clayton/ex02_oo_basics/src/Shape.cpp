#include "Shape.h"
#include <string.h>

//Shape constructor
Shape::Shape(double perimeter=0, double area=0, std::string type="", int sides=0) {
  m_perimeter = perimeter;
  m_area = area;
  m_type = type;
  m_sides = sides;
}

/** Return a string containing information for a given shape
 *  @return shape string
 */ 
std::string Shape::shapeToString() {
  std::string periString = std::to_string(m_perimeter);
  std::string areaString = std::to_string(m_area);
  std::string sideString = std::to_string(m_sides);

  std::string retnString = sideString + " sided " + m_type + " with p=" + periString + ", a=" + areaString;
  return retnString;
}

//Mutator methods
void Shape::setPerimeter(double perimeter) {
  m_perimeter = perimeter;
}

void Shape::setArea(double area) {
  m_area = area;
}

void Shape::setType(std::string type) {
  m_type = type;
}

void Shape::setSides(int sides) {
  m_sides = sides;
}

//Accessor methods
const double Shape::getPerimeter() {
  return m_perimeter;
}

const double Shape::getArea() {
  return m_area;
}

const std::string Shape::getType(){
  return m_type;
}

const int Shape::getSides() {
  return m_sides;
}  