#include "ShapeSorter.h"

ShapeSorter::ShapeSorter(std::vector<Shape *> shapes) : m_shapes{shapes} {}

/** Prints out the Shapes that match a chosen type
 *
 * @param type The Shape type
 *
 */
void ShapeSorter::printByType(std::string type) {
  for (Shape *shape : m_shapes) {
    if (shape->getType() == type) {
      std::cout << shape->getType() + " with perimeter "
                << shape->getPerimeter() << " and area " << shape->getArea()
                << "\n";
    }
  }
}

/** Prints out the Shapes that match a chosen number of sides
 *
 * @param sides The number of sides
 *
 */
void ShapeSorter::printBySides(int sides) {
  for (Shape *shape : m_shapes) {
    if (shape->getSides() == sides) {
      std::cout << shape->getType() + " with perimeter "
                << shape->getPerimeter() << " and area " << shape->getArea()
                << "\n";
    }
  }
}

bool comparePerimeters(Shape *lhs, Shape *rhs) {
  return lhs->getPerimeter() > rhs->getPerimeter();
}

bool compareAreas(Shape *lhs, Shape * rhs) {
  return lhs->getArea() > rhs->getArea();
}

/** Prints out the Shapes in order of area descending
 *
 *
 */
void ShapeSorter::printByArea() {
  // sorts the Shapes using the comparison function
  std::sort(m_shapes.begin(), m_shapes.end(), compareAreas);

  // prints each Shape
  for (Shape *shape : m_shapes) {
    std::cout << shape->getType() + " with perimeter " << shape->getPerimeter()
              << " and area " << shape->getArea() << "\n";
  }
}

/** Prints out the Shapes in order of perimeter descending
 *
 *
 */
void ShapeSorter::printByPerimeter() {
  // sorts the Shapes using the comparison function
  std::sort(m_shapes.begin(), m_shapes.end(), comparePerimeters);

  // prints each shape
  for (Shape *shape : m_shapes) {
    std::cout << shape->getType() + " with perimeter " << shape->getPerimeter()
              << " and area " << shape->getArea() << "\n";
  }
}
