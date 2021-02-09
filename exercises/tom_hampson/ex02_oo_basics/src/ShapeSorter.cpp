#include "ShapeSorter.h"

#include <algorithm>
#include <iostream>

ShapeSorter::~ShapeSorter()
{
}

/**
 * @brief Print all shapes with specified shape type (e.g. "circle").
 * @param shapeType 
*/
void ShapeSorter::printShapesOfType(const std::string& shapeType) const
{
  std::cout << "Shapes of type \"" << shapeType << "\":" << std::endl;

  for (auto shape : m_shapes)
  {
    if (shape->shapeType() == shapeType)
    {
      shape->print();
    }
  }
}

/**
 * @brief Print all shapes with n sides.
 * @param n 
*/
void ShapeSorter::printShapesWithNSides(const int n) const
{
  std::cout << "Shapes with " << n << " sides:" << std::endl;
  for (auto shape : m_shapes)
  {
    if (shape->nSides() == n)
    {
      shape->print();
    }
  }
}

/**
 * @brief Print all shapes by area in descending order.
*/
void ShapeSorter::printShapesAreaDescending() const
{
  //Make a copy of the shapes vector so we preserve the order of the member shape vector.
  std::vector<std::shared_ptr<Shape>> sortedShapes = m_shapes;
  std::sort(sortedShapes.begin(), sortedShapes.end(), compareArea);

  std::cout << "Shapes ordered by area:" << std::endl;
  for (auto shape : sortedShapes)
  {
    shape->print();
  }
}

/**
 * @brief Print all shapes in descending order of perimeter size.
*/
void ShapeSorter::printShapesPerimeterDescending() const
{
  //Make a copy of the shapes vector so we preserve the order of the member shape vector.
  std::vector<std::shared_ptr<Shape>> sortedShapes = m_shapes;
  std::sort(sortedShapes.begin(), sortedShapes.end(), comparePerimeter);

  std::cout << "Shapes ordered by perimeter:" << std::endl;
  for (auto shape : sortedShapes)
  {
    shape->print();
  }
}

/**
 * @brief Add a shape to the shape sorter.
 * @param shape 
*/
void ShapeSorter::addShape(std::shared_ptr<Shape> shape)
{
  if (nullptr != shape)
  {
    m_shapes.push_back(shape);
  }
}

/**
 * @brief Remove a shape from the shape sorter.
 * @param shape 
*/
void ShapeSorter::removeShape(std::shared_ptr<Shape> shape)
{
  if (nullptr != shape)
  {
    for (auto it = m_shapes.begin(); it != m_shapes.end(); ++it)
    {
      if (*it == shape)
      {
        m_shapes.erase(it);
        return;
      }
    }
  }
}

/**
 * @brief Static function for comparing two shapes based on area.
 * @param shapeA 
 * @param shapeB 
 * @return true if shapeA has larger area than shapeB.
*/
bool ShapeSorter::compareArea(std::shared_ptr<const Shape> shapeA, std::shared_ptr<const Shape> shapeB)
{
  return shapeA->area() > shapeB->area();
}

/**
 * @brief Static function for comparing two shapes based on perimeter size
 * @param shapeA 
 * @param shapeB 
 * @return true if shapeA has a larger perimeter than shapeB
*/
bool ShapeSorter::comparePerimeter(std::shared_ptr<const Shape> shapeA, std::shared_ptr<const Shape> shapeB)
{
  return shapeA->perimeter() > shapeB->perimeter();
}
