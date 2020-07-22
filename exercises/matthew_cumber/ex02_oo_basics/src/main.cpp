#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iomanip>

#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapeSorter.h"

int main(int argc, char **argv)
{
  // Create vector of shapes
  std::vector<std::unique_ptr<Shape>> shapes;

  // Add 3 squares, 2 rectangles, 3 circles, and 2 triangles
  shapes.push_back(std::make_unique<Square>(3));
  shapes.push_back(std::make_unique<Square>(3));
  shapes.push_back(std::make_unique<Square>(5));
  shapes.push_back(std::make_unique<Rectangle>(2,4));
  shapes.push_back(std::make_unique<Rectangle>(3,5));
  shapes.push_back(std::make_unique<Circle>(2));
  shapes.push_back(std::make_unique<Circle>(2));
  shapes.push_back(std::make_unique<Circle>(3));
  shapes.push_back(std::make_unique<Triangle>(3,5));
  shapes.push_back(std::make_unique<Triangle>(5,2));

  // Print all shapes
  for(const auto &shape : shapes)
  {
    std::cout << "=========================" << std::endl;
    std::cout << "Shape Type : " << shape->getType() << std::endl;
    std::cout << "Shape Number of Sides : " << shape->getNumSides() << std::endl;
    std::cout << "Shape Area : " << shape->area() << std::endl;
    std::cout << "Shape Perimeter" << shape->perimeter() << std::endl;
  }
  std::cout << "=========================" << std::endl;

  // Create a shape sorter and test it's methods
  ShapeSorter<Shape> sorter;

  std::cout << "Find Squares" << std::endl;
  sorter.findType(shapes, "Square");
  std::cout << std::endl;
  std::cout << "Find Circles" << std::endl;
  sorter.findType(shapes, "Circle");
  std::cout << std::endl;
  std::cout << "Find 3 Sides" << std::endl;
  sorter.findSides(shapes, 3);
  std::cout << std::endl;
  std::cout << "Find 4 Sides" << std::endl;
  sorter.findSides(shapes, 4);
  std::cout << std::endl;
  std::cout << "Order by Perimeter" << std::endl;
  sorter.printOrderPerimeter(shapes);
  std::cout << std::endl;
  std::cout << "Order by Area" << std::endl;
  sorter.printOrderArea(shapes);
}