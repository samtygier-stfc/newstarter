#ifndef SHAPE_SORTER_H
#define SHAPE_SORTER_H

#include "Shape.h"

#include <algorithm>
#include <iostream>
#include <vector>

class ShapeSorter {
private:
  std::vector<Shape *> m_shapes;

public:
  /// Constructor
  ShapeSorter(std::vector<Shape *> shapes);

  /// Prints shapes that match a given type
  void printByType(std::string type) const;

  /// Prints shapes that match a given number of sides
  void printBySides(int sides) const;

  /// Prints all shapes in order of area descending
  void printByArea();

  /// Prints all shapes in order of perimeter descending
  void printByPerimeter();
};

/// Compares two perimeters for sorting
bool comparePerimeters(Shape *lhs, Shape *rhs);

/// Compares two areas for sorting
bool compareAreas(Shape *lhs, Shape *rhs);

#endif // SHAPE_SORTER_H
