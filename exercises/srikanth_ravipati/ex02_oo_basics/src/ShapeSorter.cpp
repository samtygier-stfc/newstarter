#include "ShapeSorter.h"

void ShapeSorter::areaDescent(std::vector<std::unique_ptr<Shape>> &vecShape) {
  std::cout << "\n" << "Sort and print shapes in the order of area descent " << "\n";
  std::sort(vecShape.begin(), vecShape.end(), [] (auto &itrShape1, auto &itrShape2)
    { return itrShape1->getArea() > itrShape2->getArea(); });
  for_each(vecShape.begin(), vecShape.end(), 
    [] (const auto &itrShape) { itrShape->printInfo(); });
}

void ShapeSorter::perimeterDescent(std::vector<std::unique_ptr<Shape>> &vecShape) {
  std::cout << "\n" << "Sort and print shapes in the order of perimeter descent " << "\n";
  std::sort(vecShape.begin(), vecShape.end(), [] (auto &itrShape1, auto &itrShape2)
    { return itrShape1->getPerimeter() > itrShape2->getPerimeter(); } );
  for_each(vecShape.begin(), vecShape.end(), 
    [] (const auto &itrShape) { itrShape->printInfo(); });
}

void ShapeSorter::equal_N_Sides(const std::vector<std::unique_ptr<Shape>> &vecShape, 
  const unsigned int &nSides) {
  std::cout << "\n" << "Print shapes that have given number of sides " << "\n";
  for_each(vecShape.begin(), vecShape.end(), [&nSides] (const auto &itrShape) 
      { if(itrShape->hasEqual_N_Sides(nSides)) { itrShape->printInfo(); }; });
}

void ShapeSorter::sameType(const std::vector<std::unique_ptr<Shape>> &vecShape, 
  const std::string &type) {
  std::cout << "\n" << "Print shapes that matches given type " << "\n";
  for_each(vecShape.begin(), vecShape.end(), [&type] (const auto &itrShape) 
    { if(itrShape->isSameType(type)) { itrShape->printInfo(); }; });
}