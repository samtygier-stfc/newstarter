#include <iostream>
#include <string>
#include <vector>

#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main(int argc, char **argv)
{
	std::cout << "Hello world" << std::endl;

  Square square(4);
  std::cout << square.getType() << std::endl;
  std::cout << square.getNumSides() << std::endl;
  std::cout << square.area() << std::endl;
  std::cout << square.perimeter() << std::endl;

  std::cout << "===================" << std::endl;

  Circle circle(4);
  std::cout << circle.getType() << std::endl;
  std::cout << circle.getNumSides() << std::endl;
  std::cout << circle.area() << std::endl;
  std::cout << circle.perimeter() << std::endl;

  std::cout << "===================" << std::endl;

  Triangle triangle(4,3);
  std::cout << triangle.getType() << std::endl;
  std::cout << triangle.getNumSides() << std::endl;
  std::cout << triangle.area() << std::endl;
  std::cout << triangle.perimeter() << std::endl;

  std::cout << "===================" << std::endl;

  Rectangle rectangle(4,8);
  std::cout << rectangle.getType() << std::endl;
  std::cout << rectangle.getNumSides() << std::endl;
  std::cout << rectangle.area() << std::endl;
  std::cout << rectangle.perimeter() << std::endl;

  std::cout << "===================" << std::endl;


>>>>>>> fcfcad4... Created Shape parent class and all child classes
}