#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"

class ShapeSorter {
public:
  ShapeSorter(std::vector<Shape>);
  void printType(std::string) const;
  void printSides(unsigned) const;
  void printAreaDescending();
  void printPerimeterDescending();

private:
  std::vector<Shape> m_vecShape;
  std::vector<Shape> m_vecShapeSorted;
};

#endif // SHAPESORTER_H