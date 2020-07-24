#include "ShapeSorter.h"
#include "Shape.h"
#include "Square.h"
#include <memory>
#include <iostream>

int main(int argc, const char** argv) {

  std::vector<Shape> shp_vect;
  Square testSquare{3};
  shp_vect.push_back(testSquare);

  ShapeSorter ss(shp_vect);
  ss.printShapesType("Square");
}