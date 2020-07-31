#include "ShapeSorter.h"
#include "Shape.h"
#include "Square.h"
#include <memory>
#include <iostream>

int main(int argc, const char** argv) {

  std::vector<std::shared_ptr<Shape>> shp_vect;
  
  std::shared_ptr<Square> sq1 = std::make_shared<Square>(3);
  shp_vect.push_back(sq1);

  //ShapeSorter ss(shp_vect);
  //ss.printShapesType("Square");
}