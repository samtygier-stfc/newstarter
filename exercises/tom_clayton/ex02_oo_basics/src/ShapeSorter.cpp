#include "ShapeSorter.h"
#include <iostream>
#include <algorithm>
#include <vector>

/** Comparator function to return true if s1 area > s2 area
 *  @param s1 reference to the first shape
 *  @param s2 reference to the second shape
 * 
 *  @return boolean to determine larger area
 */ 
static bool areaCompare(std::shared_ptr<Shape>& s1, std::shared_ptr<Shape>& s2) {
  return (s1->getArea() > s2->getArea());
}

/** Comparator function to return true if s1 perimeter > s2 perimeter
 *  @param s1 reference to the first shape
 *  @param s2 reference to the second shape
 * 
 *  @return boolean to determine larger perimeter
 */ 
static bool periCompare(std::shared_ptr<Shape> s1, std::shared_ptr<Shape> s2) {
  return (s1->getPerimeter() > s2->getPerimeter());
}

//ShapeSorter constructor
ShapeSorter::ShapeSorter(std::vector<std::shared_ptr<Shape>> shpVect) {
  m_shpVect = shpVect;
  m_vecLen = shpVect.size();
}

/** Print out all shapes of a given type, or an error message if no
 *  shapes of that type are found
 *  @param string type for type of string
 */ 
const void ShapeSorter::printShapesType(const std::string type) {
  bool shapeTypeFound = false;
  for(auto shape_ptr : m_shpVect) {
    if(shape_ptr->getType().compare(type) == 0) {
      std::cout << shape_ptr->shapeToString() << std::endl;
      shapeTypeFound = true;
    }
  }
  if(!shapeTypeFound) {
    std::cout << "No shapes found of type " << type << std::endl;
  }
}

/** Print out all shapes of a given number of sides, or an error
 *  message if no shapes of that type are found
 *  @param int sides for no of sides
 */ 
const void ShapeSorter::printShapesSides(int sides) {
  bool shapeTypeFound = false;
  for(auto shape_ptr : m_shpVect) {
    if(shape_ptr->getSides() == sides) {
      std::cout << shape_ptr->shapeToString() << std::endl;
      shapeTypeFound = true;
    }
  }
  if(!shapeTypeFound) {
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
  for(auto &shape : m_shpVect) {
    std::cout << shape->shapeToString() << std::endl;
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
  for(auto &shape : m_shpVect) {
    std::cout << shape->shapeToString() << std::endl;
  }
}

//
//Mutator methods
//
void ShapeSorter::setShpVect(std::vector<std::shared_ptr<Shape>> shpVect) {
  m_shpVect = shpVect;
}

//
//Accessor methods
//
std::vector<std::shared_ptr<Shape>> ShapeSorter::getShpVect() {
  return m_shpVect;
}

int ShapeSorter::getVecLen() {
  return m_vecLen;
}

