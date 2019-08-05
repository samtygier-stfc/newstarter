#include "ShapeSorter.h"

ShapeSorter::ShapeSorter() : m_shapes(0) {}

ShapeSorter::ShapeSorter(std::vector<Shape *> shapes) : m_shapes(shapes) {}

void printShape(Shape *shape) {
  std::cout << "The shape " << shape->getType() << " has " << shape->getSides()
            << " sides, a perimeter of " << shape->perimeter() << " and area "
            << shape->area() << "\n";
}

void ShapeSorter::printType() const {
  std::cout << "TYPES"
            << "\n";
  for (auto const &shape : m_shapes) {
    printShape(shape);
  }
  std::cout << "\n";
}

void ShapeSorter::printSide(int side) const {
  std::cout << "SHAPES WITH MORE THAN " << side << " SIDES"
            << "\n";
  for (auto const &shape : m_shapes) {
    if (shape->getSides() == side) {
      printShape(shape);
    }
  }
  std::cout << "\n";
}

bool compareShapesArea(Shape *shape1, Shape *shape2) {
  return shape1->area() < shape2->area();
}

bool compareShapesPerimeter(Shape *shape1, Shape *shape2) {
  return shape1->perimeter() < shape2->perimeter();
}

void ShapeSorter::printAreaDescending() {
  std::cout << "SHAPE AREA"
            << "\n";
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesArea);
  for (auto const &shape : m_shapes) {
    printShape(shape);
  }
  std::cout << "\n";
}

void ShapeSorter::printPerimeterDescending() {
  std::cout << "SHAPE PERIMETER"
            << "\n";
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesPerimeter);
  for (auto const &shape : m_shapes) {
    printShape(shape);
  }
  std::cout << "\n";
}
