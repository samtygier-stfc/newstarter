#ifndef SHAPESORTER_H
#define SHAPESORTER_H
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>
#include <vector>

class ShapeSorter {
public:
  ShapeSorter();
  ShapeSorter(std::vector<Shape *> shapes);
  void printType() const;
  void printSide(int sides) const;
  void printAreaDescending();
  void printPerimeterDescending();

private:
  std::vector<Shape *> m_shapes;
};
#endif // SHAPESORTER_H
