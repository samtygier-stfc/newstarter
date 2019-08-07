#include "main.h"

int main() {
  // populate vector with unique pointers to ShapeBase objects
  std::vector<std::unique_ptr<ShapeBase>> vecShape;
  vecShape.emplace_back(std::make_unique<Circle>(4));
  vecShape.emplace_back(std::make_unique<Circle>(4));
  vecShape.emplace_back(std::make_unique<Circle>(10));
  vecShape.emplace_back(std::make_unique<Triangle>(4, 7));
  vecShape.emplace_back(std::make_unique<Triangle>(0, 2));
  vecShape.emplace_back(std::make_unique<Rectangle>(5, 3));
  vecShape.emplace_back(std::make_unique<Rectangle>(4));

  // print sorted data
  ShapeSorter::printType(vecShape, "Circle");
  ShapeSorter::printType(vecShape, "Triangle");
  ShapeSorter::printType(vecShape, "Rectangle");
  ShapeSorter::printSides(vecShape, 1);
  ShapeSorter::printSides(vecShape, 3);
  ShapeSorter::printSides(vecShape, 4);
  ShapeSorter::printSides(vecShape, 13);
  ShapeSorter::printAreaDescending(vecShape);
  ShapeSorter::printPerimeterDescending(vecShape);
}