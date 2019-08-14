#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "ShapeBase.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

typedef std::vector<std::unique_ptr<ShapeBase>> vecPtr;

class ShapeSorter {
public:
  // member functions to print data
  static void printType(vecPtr &vecShape, std::string type);
  static void printNumberOfSides(vecPtr &vecShape, unsigned int numberOfSides);
  static void printAreaDescending(vecPtr &vecShape);
  static void printPerimeterDescending(vecPtr &vecShape);
};

#endif // SHAPESORTER_H