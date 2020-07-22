#include "rect.h"
#include <iostream>

int main(int, char **)
{
  Rect* myRect = new Rect(10, 20);
  std::cout << myRect->getSides();
}