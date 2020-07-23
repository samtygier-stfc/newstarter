#include "Shapesorter.h"
#include <iostream>
#include <algorithm>
#include <vector>

//ShapeSorter constructor
ShapeSorter::ShapeSorter(std::vector<Shape> shpVect) {
  m_shpVect = shpVect;
  m_vecLen = shpVect.size();
}

// Typedef to be used to iterate through the vector
typedef std::vector<Shape>::size_type VecSz;

/** Print out all shapes of a given type, or an error message if no
 *  shapes of that type are found
 *  @param string type for type of string
 */ 
const void ShapeSorter::printShapesType(const std::string type) {
  bool flag = false;
  for(VecSz i = 0; i < getVecLen(); ++i) {
    if(m_shpVect[i].getType().compare(type) == 0) {
      m_shpVect[i].shapeToString();
      flag = true;
    }
  }
  if(!flag) {
    std::cout << "No shapes found of type " << type << std::endl;
  }
}

/** Print out all shapes of a given number of sides, or an error
 *  message if no shapes of that type are found
 *  @param int sides for no of sides
 */ 
const void ShapeSorter::printShapesSides(int sides) {
  bool flag = false;
  for(VecSz i = 0; i < getVecLen(); ++i) {
    if(m_shpVect[i].getSides() == sides) {
      m_shpVect[i].shapeToString();
      flag = true;
    }
  }
  if(!flag) {
    std::cout << "No shapes with " << std::to_string(sides) << " found" << std::endl;
  }
}

/** Sort the vector by descending area, then print shapes in sorted
 *  order. Print an error message if no shapes are found.
 */ 
void ShapeSorter::printSortShapesByArea() {
  if(m_shpVect.empty()) {
    std::cout << "Vector empty, no shapes to show" << std::endl;
    return;
  }
  std::sort(m_shpVect.begin(), m_shpVect.end(), areaCompare);
  for(VecSz i = 0; i < getVecLen(); ++i) {
    m_shpVect[i].shapeToString();
  }
}

/** Sort the vector by descending perimeter, then print shapes in 
 *  sorted order. Print an error message if no shapes are found.
 */ 
void ShapeSorter::printSortShapesByPerimeter() {
  if(m_shpVect.empty()) {
    std::cout << "Vector empty, no shapes to show" << std::endl;
    return;
  }
  std::sort(m_shpVect.begin(), m_shpVect.end(), periCompare);
  for(VecSz i = 0; i < getVecLen(); ++i) {
    m_shpVect[i].shapeToString();
  }
}

/** Comparator function to return true if s1 area > s2 area
 *  @param s1 reference to the first shape
 *  @param s2 reference to the second shape
 * 
 *  @return boolean to determine larger area
 */ 
bool ShapeSorter::areaCompare(Shape &s1, Shape &s2) {
  return (s1.getArea() > s2.getArea());
}

/** Comparator function to return true if s1 perimeter > s2 perimeter
 *  @param s1 reference to the first shape
 *  @param s2 reference to the second shape
 * 
 *  @return boolean to determine larger perimeter
 */ 
bool ShapeSorter::periCompare(Shape& s1, Shape& s2) {
  return (s1.getPerimeter() > s2.getPerimeter());
}

//
//Mutator methods
//
void ShapeSorter::setShpVect(std::vector<Shape> shpVect) {
  m_shpVect = shpVect;
}

//
//Accessor methods
//
std::vector<Shape> ShapeSorter::getShpVect() {
  return m_shpVect;
}

int ShapeSorter::getVecLen() {
  return m_vecLen;
}

