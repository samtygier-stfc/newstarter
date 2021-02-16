#include "ShapeSorter.h"

void ShapeSorter::areaDescent(std::vector<std::unique_ptr<Shape>> &vecShape) {
  std::cout << "\n" << "Sort and print shapes in the order of area descent " << "\n";
  std::sort(vecShape.begin(), vecShape.end(), [] (auto &itrShape1, auto &itrShape2)
    { return itrShape1->getArea() > itrShape2->getArea(); });
  for (auto &vecShapeElement : vecShape) {
    vecShapeElement->printInfo();
  }
}

void ShapeSorter::perimeterDescent(std::vector<std::unique_ptr<Shape>> &vecShape) {
  std::cout << "\n" << "Sort and print shapes in the order of perimeter descent " << "\n";
  std::sort(vecShape.begin(), vecShape.end(), [] (auto &itrShape1, auto &itrShape2)
    { return itrShape1->getPerimeter() > itrShape2->getPerimeter(); } );
  for (auto &vecShapeElement : vecShape) {
    vecShapeElement->printInfo();
  }
}

void ShapeSorter::equal_N_Sides(const std::vector<std::unique_ptr<Shape>> &vecShape, 
  const unsigned int &nSides) {
  std::cout << "\n" << "Print shapes that have given number of sides " << "\n";
  for (auto &vecShapeElement : vecShape) {
    if (vecShapeElement->hasEqual_N_Sides(nSides)) { vecShapeElement->printInfo(); };
  }
}

void ShapeSorter::sameType(const std::vector<std::unique_ptr<Shape>> &vecShape, 
  const std::string &type) {
  std::cout << "\n" << "Print shapes that matches given type " << "\n";
  for (auto &vecShapeElement : vecShape) {
    if (vecShapeElement->isSameType(type)) { vecShapeElement->printInfo(); };
  }
}