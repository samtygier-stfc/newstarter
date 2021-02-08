/**
 * Skeleton main routine
 */
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

int main(int, char **)
{
  Square square(5);
  square.print();

  Triangle triangle(3, 5);
  triangle.print();

  Circle circle(4);
  circle.print();

  Rectangle rectangle(2, 4);
  rectangle.print();

  return 0;
}