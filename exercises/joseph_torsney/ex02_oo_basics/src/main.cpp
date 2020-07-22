#include "rect.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"

#include <iostream>

int main(int, char **)
{
  Rect* myRect = new Rect(10, 20); // why do these have to be pointers?
  Square* mySquare = new Square(10);
  Circle* myCircle = new Circle(10);
  Triangle* myTriangle = new Triangle(10, 20);

  std::cout 
    << myRect->getPerimeter() << std::endl
    << mySquare->getPerimeter() << std::endl
    << myCircle->getPerimeter() << std::endl
    << myTriangle->getPerimeter() << std::endl
    << std::endl;
}