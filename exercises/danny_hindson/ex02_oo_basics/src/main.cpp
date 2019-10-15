// Mantid Repository : https://github.com/mantidproject/mantid
//
// Copyright &copy; 2019 ISIS Rutherford Appleton Laboratory UKRI,
//     NScD Oak Ridge National Laboratory, European Spallation Source
//     & Institut Laue - Langevin
// SPDX - License - Identifier: GPL - 3.0 +

#include "Circle.h"
#include "Rectangle.h"
#include "ShapeSorter.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include <iostream>
#include <string>
#include <vector>

int main(int, char **)
{
  Square sq(2.5);
  Rectangle r(3, 7);
  Circle c(4.1);
  Triangle t(1, 10);

  // create vector of pointers to Shape rather than actual Shapes so the polymorphism works
  std::vector<Shape*> shapeVector;

  shapeVector.push_back(&sq);
  shapeVector.push_back(&r);
  shapeVector.push_back(&c);
  shapeVector.push_back(&t);

  ShapeSorter sorter(shapeVector);
  std::cout << "Test Print Shapes that match type" << std::endl;
  sorter.printShapes("Square");
  std::cout <<std::endl << "Test Print Shapes that match n of sides" << std::endl;
  sorter.printShapes(3);
  std::cout << std::endl << "Test Print Shapes in order of area" << std::endl;
  sorter.printOrderedByArea();
  std::cout << std::endl << "Test Print Shapes in order of perimeter" << std::endl;
  sorter.printOrderedByPerimeter();
}
