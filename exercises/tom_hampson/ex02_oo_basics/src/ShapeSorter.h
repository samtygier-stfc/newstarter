#pragma once
#include "Shape.h"

#include <vector>
#include <memory>

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
  
  void addShape(std::shared_ptr<Shape>);
  void removeShape(std::shared_ptr<Shape>);

  static bool compareArea(std::shared_ptr<const Shape> shapeA, std::shared_ptr<const Shape> shapeB);
  static bool comparePerimeter(std::shared_ptr<const Shape> shapeA, std::shared_ptr<const Shape> shapeB);

private:
  std::vector<std::shared_ptr<Shape>> m_shapes;
};