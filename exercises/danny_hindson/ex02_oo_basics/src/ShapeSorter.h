// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shape.h"
#include <vector>

class ShapeSorter {
public:
  ShapeSorter(std::vector<Shape*> v) : shapeVec(std::move(v)) {}; //move semantics - if passed rvalue in here would be 0 copies, if pass lvalue then 1 copy
  virtual ~ShapeSorter() {};
  void printShapes(const std::string& ShapeType) const;
  void printShapes(int nSides) const;
  void printOrderedByArea() const;
  void printOrderedByPerimeter() const;
private:
  std::vector<Shape*> shapeVec;
};

#endif /* SHAPESORTER_H_*/