#include "rect.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "shapeSorter.h"

#include <iostream>
#include <vector>

int main(int, char **)
{
  Rect* myRect = new Rect(10, 20); // why do these have to be pointers?
  Square* mySquare = new Square(10);
  Circle* myCircle = new Circle(10);
  Triangle* myTriangle = new Triangle(10, 20);

  ShapeSorter* sorter = new ShapeSorter(
    { myRect, mySquare, myCircle, myTriangle }
  );
  sorter->printMatching("triangle");
  sorter->printSides(4);
}