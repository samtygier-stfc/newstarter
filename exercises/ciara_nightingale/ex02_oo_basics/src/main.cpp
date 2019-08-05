#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Triangle.h"
#include <vector>

int main() {
  std::vector<Shape *> shapes;
  Circle circle(3.0);
  Rectangle rectangle(5.0, 9.0);
  Rectangle square(3.0);
  Triangle triangle(3.0, 8.0);
  shapes.push_back(&rectangle);
  shapes.push_back(&square);
  shapes.push_back(&circle);
  shapes.push_back(&triangle);
  auto sorted = ShapeSorter(shapes);
  sorted.printType();
  sorted.printSide(3);
  sorted.printPerimeterDescending();
  sorted.printAreaDescending();
  return 0;
}
