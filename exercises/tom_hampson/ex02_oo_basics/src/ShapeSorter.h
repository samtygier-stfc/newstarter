#pragma once
#include "Shape.h"

#include <vector>

/**
 * @brief "Shape sorter" class that stores a vector of shapes and contains
 * a few functions for printing the shapes.
*/
class ShapeSorter
{
public:
  ShapeSorter() {};
  virtual ~ShapeSorter();

  void printShapesOfType(const std::string& shapeType) const;
  void printShapesWithNSides(const int n) const;
  void printShapesAreaDescending() const;
  void printShapesPerimeterDescending() const;
  
  void addShape(Shape* shape);
  void removeShape(Shape* shape);

  static bool compareArea(const Shape* shapeA, const Shape* shapeB);
  static bool comparePerimeter(const Shape* shapeA, const Shape* shapeB);

private:
  std::vector<Shape*> m_shapes;
};