#include "rect.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"

#include <iostream>
#include <vector>

int main(int, char **)
{
  Rect* myRect = new Rect(10, 20); // why do these have to be pointers?
  Square* mySquare = new Square(10);
  Circle* myCircle = new Circle(10);
  Triangle* myTriangle = new Triangle(10, 20);

  std::vector<Shape*> shapes = { myRect, mySquare, myCircle, myTriangle };

  std::cout 
    << myRect->getSides() << std::endl
    << mySquare->getSides() << std::endl
    << myCircle->getSides() << std::endl
    << myTriangle->getSides() << std::endl
    << std::endl;
}