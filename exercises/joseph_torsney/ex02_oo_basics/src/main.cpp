#include "rect.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "shapeSorter.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int, char **)
{
  std::shared_ptr<Rect> myRect = std::make_shared<Rect>(10, 10);
  std::shared_ptr<Square> mySquare = std::make_shared<Square>(10);
  std::shared_ptr<Circle> myCircle = std::make_shared<Circle>(10);
  std::shared_ptr<Triangle> myTriangle = std::make_shared<Triangle>(10, 10);

  ShapeSorter sorter = ShapeSorter(
    { myRect, mySquare, myCircle, myTriangle }
  );

  sorter.printMatching("rect");
  std::cout << std::endl;
  sorter.printSides(4);
  std::cout << std::endl;
  sorter.printAreas();
  std::cout << std::endl;
  sorter.printPerimeters();
}