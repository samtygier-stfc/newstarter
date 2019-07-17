#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

int main() {
  std::vector<Shape *> shapes;

  // creates a variety of Shapes
  Triangle triangle1{3, 5};
  Triangle triangle2{9, 7};
  Square square1{6};
  Square square2{2};
  Circle circle1{4};
  Circle circle2{10};
  Rectangle rectangle1{2, 8};
  Rectangle rectangle2{4, 3};

  // puts the shapes in a vector
  shapes.push_back(&triangle1);
  shapes.push_back(&triangle2);
  shapes.push_back(&square1);
  shapes.push_back(&square2);
  shapes.push_back(&circle1);
  shapes.push_back(&circle2);
  shapes.push_back(&rectangle1);
  shapes.push_back(&rectangle2);

  // demonstrates each ShapeSorter function
  ShapeSorter test{shapes};
  std::cout << "Printing just circles:\n";
  test.printByType("Circle");

  std::cout << "\nPrinting all shapes with 4 sides:\n";
  test.printBySides(4);

  std::cout << "\nPrinting all shapes in order of area descending:\n";
  test.printByArea();

  std::cout << "\nPrinting all shapes in order of perimeter descending:\n";
  test.printByPerimeter();

  return 0;
}
