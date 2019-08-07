#include "ShapeSorter.h"

/** Prints shapes of given type
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 * @param type: type of shape
 *
 */
void ShapeSorter::printType(vecPtr & vecShape, std::string type) {
  unsigned int matchCounter = 0;
  std::cout << std::string(80, '*') << "\n";

  // loop through vector of pointers to ShapeBase objects
  for (std::vector<std::unique_ptr<ShapeBase>>::const_iterator it = vecShape.begin();
       it != vecShape.end(); ++it) {
    // check for match
    if ((*it)->getName() == type) {
      std::cout << "Shape " << ++matchCounter << ":\n\tShape is of type "
                << type
                << ", with area " << (*it)->getArea()
                << " and perimeter " << (*it)->getPerimeter()
                << "\n\n";
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
 * @param sides: number of sides
 *
 */
void ShapeSorter::printSides(vecPtr & vecShape, unsigned int sides) {
  unsigned int matchCounter = 0;
  std::cout << std::string(80, '*') << "\n";

  // loop through vector of pointers to ShapeBase objects
  for (std::vector<std::unique_ptr<ShapeBase>>::const_iterator it = vecShape.begin();
     it != vecShape.end(); ++it) {
    // check for match
    if ((*it)->getSides() == sides) {
      std::cout << "Shape " << ++matchCounter << ":\n\tShape is of type "
                << (*it)->getName() << ", with area "
                << (*it)->getArea() << " and perimeter "
                << (*it)->getPerimeter() << "\n\n";
    }
  }
  // repot no matches
  if (matchCounter == 0) {
    std::cout << "No instance of shape with " << sides << " sides\n\n";
  }
}

/** Prints shapes in order of descending area
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 *
 */
void ShapeSorter::printAreaDescending(vecPtr & vecShape) {
  std::cout << std::string(80, '*') << "\n";
  // sort pointed-to vector objects into descending order of area
  std::sort(vecShape.begin(), vecShape.end(),
            [](const std::unique_ptr<ShapeBase> &a,
               const std::unique_ptr<ShapeBase> &b) {
              return a->getArea() > b->getArea();
            });
  unsigned int counter = 0;
  for (std::vector<std::unique_ptr<ShapeBase>>::iterator it = vecShape.begin();
       it != vecShape.end(); ++it) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << (*it)->getName() << ", with area "
              << (*it)->getArea() << " and perimeter "
              << (*it)->getPerimeter() << "\n\n";
  }
}

/** Prints shapes in order of descending perimeter
 *
 * @param vecShape: vector of unique pointers to ShapeBase objects
 *
 */
void ShapeSorter::printPerimeterDescending(vecPtr & vecShape) {
  std::cout << std::string(80, '*') << "\n";
  // sort pointed-to vector objects into descending order of area
  std::sort(vecShape.begin(), vecShape.end(),
            [](const std::unique_ptr<ShapeBase> &a,
               const std::unique_ptr<ShapeBase> &b) {
              return a->getPerimeter() > b->getPerimeter();
            });
  unsigned int counter = 0;
  for (std::vector<std::unique_ptr<ShapeBase>>::iterator it = vecShape.begin();
       it != vecShape.end(); ++it) {
    std::cout << "Shape " << ++counter << ":\n\tShape is of type "
              << (*it)->getName() << ", with area "
              << (*it)->getArea() << " and perimeter "
              << (*it)->getPerimeter() << "\n\n";
  }
}