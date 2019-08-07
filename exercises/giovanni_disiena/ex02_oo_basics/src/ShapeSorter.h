#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "ShapeBase.h"

typedef std::vector<std::unique_ptr<ShapeBase>> vecPtr;

class ShapeSorter {
public:
  // member functions to print data
  static void printType(vecPtr &, std::string);
  static void printSides(vecPtr &, unsigned int);
  static void printAreaDescending(vecPtr &);
  static void printPerimeterDescending(vecPtr &);

private:
};

#endif // SHAPESORTER_H