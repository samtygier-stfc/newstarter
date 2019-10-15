// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "ShapeSorter.h"
#include "Shape.h"
#include <algorithm>
#include <iostream>
#include <string>

/**
 * Print list of shapes of a given type
 * @param shapeType A string describing what sort of shapes should be printed eg Circle
  */
void ShapeSorter::printShapes(std::string shapeType) const {
  for (std::vector<Shape*>::const_iterator it = shapeVec.begin(); it != shapeVec.end(); it++) {
    if ((*it)->getShapeType() == shapeType) {
      std::cout << (*it)->getShapeDetails() << std::endl;
    }
  }
}

/**
 * Print list of shapes of a given type
 * @param nSides Number of sides for shapes that should be printed
  */
void ShapeSorter::printShapes(int nSides) const  {
  for (std::vector<Shape*>::const_iterator it = shapeVec.begin(); it != shapeVec.end(); it++) {
    if ((*it)->getShapeSides() == nSides) {
      std::cout << (*it)->getShapeDetails() << std::endl;
    }
  }
}

bool CompareBasedOnArea(const Shape* s1, const Shape* s2) {
  return (s1->area() < s2->area());
}

bool CompareBasedOnPerimeter(const Shape* s1, const Shape* s2) {
  return (s1->perimeter() < s2->perimeter());
}

/**
 * Print list of shapes ordered by area
  */
void ShapeSorter::printOrderedByArea() const {
  std::vector<Shape*> sortedVec = shapeVec;
  std::sort(sortedVec.begin(), sortedVec.end(), CompareBasedOnArea);
  for (std::vector<Shape*>::const_iterator it = sortedVec.begin(); it != sortedVec.end(); it++) {
    std::cout << (*it)->getShapeDetails() << std::endl;
  }
}

/**
 * Print list of shapes ordered by perimeter
  */
void ShapeSorter::printOrderedByPerimeter() const{
  std::vector<Shape*> sortedVec = shapeVec;
  std::sort(sortedVec.begin(), sortedVec.end(), CompareBasedOnPerimeter);
  for (std::vector<Shape*>::const_iterator it = sortedVec.begin(); it != sortedVec.end(); it++) {
    std::cout << (*it)->getShapeDetails() << std::endl;
  }
}