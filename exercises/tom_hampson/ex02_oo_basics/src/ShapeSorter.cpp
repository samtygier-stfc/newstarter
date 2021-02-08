#include "ShapeSorter.h"

#include <algorithm>
#include <iostream>

ShapeSorter::~ShapeSorter()
{
  for (auto shape : m_shapes)
  {
    delete shape;
  }
}

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

void ShapeSorter::printShapesAreaDescending() const
{
  //Make a copy of the shapes vector so we preserve the order of the member shape vector.
  std::vector<Shape*> sortedShapes = m_shapes;
  std::sort(sortedShapes.begin(), sortedShapes.end(), compareArea);

  std::cout << "Shapes ordered by area:" << std::endl;
  for (auto shape : sortedShapes)
  {
    shape->print();
  }
}

void ShapeSorter::printShapesPerimeterDescending() const
{
  //Make a copy of the shapes vector so we preserve the order of the member shape vector.
  std::vector<Shape*> sortedShapes = m_shapes;
  std::sort(sortedShapes.begin(), sortedShapes.end(), comparePerimeter);

  std::cout << "Shapes ordered by perimeter:" << std::endl;
  for (auto shape : sortedShapes)
  {
    shape->print();
  }
}

void ShapeSorter::addShape(Shape* shape)
{
  if (nullptr != shape)
  {
    m_shapes.push_back(shape);
  }
}

void ShapeSorter::removeShape(Shape* shape)
{
  if (nullptr != shape)
  {
    for (auto it = m_shapes.begin(); it != m_shapes.end(); ++it)
    {
      if (*it == shape)
      {
        m_shapes.erase(it);
        delete shape;
        return;
      }
    }
  }
}

bool ShapeSorter::compareArea(const Shape* shapeA, const Shape* shapeB)
{
  return shapeA->area() > shapeB->area();
}

bool ShapeSorter::comparePerimeter(const Shape* shapeA, const Shape* shapeB)
{
  return shapeA->perimeter() > shapeB->perimeter();
}
