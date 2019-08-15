#include "ShapeSorter.h"

/** Prints shapes of given type
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 * @param type: type of shape
 *
 */
void ShapeSorter::printType(vecPtr &vecShape, std::string type) {
  unsigned int matchCounter = 0;
  std::cout << std::string(80, '*') << "\n";

  // loop through vector of pointers to ShapeBase objects
  for (const auto &it : vecShape) {
    // check for match
    if (it->getName() == type) {
      std::cout << "Shape " << ++matchCounter << ":\n\tShape is of type "
                << type << ", with area " << it->getArea() << " and perimeter "
                << it->getPerimeter() << "\n\n";
    }
  }
  // report no matches
  if (matchCounter == 0) {
    std::cout << "No instance of shape type " << type << "\n\n";
  }
}

/** Prints shapes of given number of sides
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 * @param numberOfSides: number of sides
 *
 */
void ShapeSorter::printNumberOfSides(vecPtr &vecShape,
                                     unsigned int numberOfSides) {
  unsigned int matchCounter = 0;
  std::cout << std::string(80, '*') << "\n";

  // loop through vector of pointers to ShapeBase objects
  for (const auto &it : vecShape) {
    // check for match
    if (it->getNumberOfSides() == numberOfSides) {
      std::cout << "Shape " << ++matchCounter << ":\n\tShape is of type "
                << it->getName() << ", with area " << it->getArea()
                << " and perimeter " << it->getPerimeter() << "\n\n";
    }
  }
  // repot no matches
  if (matchCounter == 0) {
    std::cout << "No instance of shape with " << numberOfSides << " sides\n\n";
  }
}

/** Prints shapes in order of descending area
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 *
 */
void ShapeSorter::printAreaDescending(vecPtr &vecShape) {
  std::cout << std::string(80, '*') << "\n";
  // sort pointed-to vector objects into descending order of area
  std::sort(vecShape.begin(), vecShape.end(),
            [](const std::unique_ptr<ShapeBase> &a,
               const std::unique_ptr<ShapeBase> &b) {
              return a->getArea() > b->getArea();
            });
  unsigned int counter = 0;
  for (const auto &it : vecShape) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << it->getName() << ", with area " << it->getArea()
              << " and perimeter " << it->getPerimeter() << "\n\n";
  }
}

/** Prints shapes in order of descending perimeter
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 *
 */
void ShapeSorter::printPerimeterDescending(vecPtr &vecShape) {
  std::cout << std::string(80, '*') << "\n";
  // sort pointed-to vector objects into descending order of area
  std::sort(vecShape.begin(), vecShape.end(),
            [](const std::unique_ptr<ShapeBase> &a,
               const std::unique_ptr<ShapeBase> &b) {
              return a->getPerimeter() > b->getPerimeter();
            });
  unsigned int counter = 0;
  for (const auto &it : vecShape) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << it->getName() << ", with area " << it->getArea()
              << " and perimeter " << it->getPerimeter() << "\n\n";
  }
}