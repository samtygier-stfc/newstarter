/**
 * Skeleton main routine
 */
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

int main(int, char **)
{
  //Square square(5);
  //square.print();

  //Triangle triangle(3, 5);
  //triangle.print();

  //Circle circle(4);
  //circle.print();

  //Rectangle rectangle(2, 4);
  //rectangle.print();

  ShapeSorter sorter;
  sorter.addShape(new Circle(3));
  sorter.addShape(new Square(5));
  sorter.addShape(new Triangle(5,4));
  sorter.addShape(new Triangle(6,4));
  sorter.addShape(new Triangle(7,4));
  sorter.addShape(new Rectangle(2,4));
  sorter.addShape(new Rectangle(5,1));

  sorter.printShapesOfType("rectangle");
  sorter.printShapesWithNSides(4);
  sorter.printShapesAreaDescending();
  sorter.printShapesPerimeterDescending();

  return 0;
}