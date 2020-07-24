#include "ShapeSorter.h"
#include "Shape.h"
#include "Square.h"
#include <memory>
#include <iostream>

int main(int argc, const char** argv) {

  std::vector<std::shared_ptr<Shape>> shp_vect;
  
  shp_vect.push_back(std::make_shared<Square>(3));

  ShapeSorter ss(shp_vect);
  ss.printShapesType("Square");
}