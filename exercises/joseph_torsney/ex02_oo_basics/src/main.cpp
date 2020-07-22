#include "rect.h"
#include "square.h"
#include <iostream>

int main(int, char **)
{
  Rect* myRect = new Rect(10, 20); // why do these have to be pointers?
  Square* mySquare = new Square(10);
  std::cout << myRect->getPerimeter() << mySquare->getPerimeter() << std::endl;
}