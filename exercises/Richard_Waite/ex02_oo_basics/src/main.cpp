#include<vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"


int main(int, char **)
{
	// populate a vector of pointers to shape base class
	std::vector<Shape*> all_shapes;
	// new allocates memory before class initilisation and returns a pointer
	all_shapes.push_back(new Square(2.0));
	all_shapes.push_back(new Rectangle(2.0,4.0));
	all_shapes.push_back(new Circle(1.0));
	all_shapes.push_back(new Triangle(1.0,3.0));

	Square s(2);
	s.print();

}