#include "ShapeSorter.h"

//construct the object if no arguments are given
ShapeSorter::ShapeSorter() : m_shapes(0) {}

//construct the object from the vector given as argument
ShapeSorter::ShapeSorter(std::vector<Shape *> shapes) : m_shapes(shapes) {}

//function to print a shape
void printShape(Shape *shape) {
  //prints the properties of the shapes so that they are identifiable
  std::cout << "The shape " << shape->getType() << " has " << shape->getSides()
            << " sides, a perimeter of " << shape->perimeter() << " and area "
            << shape->area() << "\n";
}

//function which prints the types of all of the shapes
void ShapeSorter::printType() const {
  std::cout << "TYPES"
            << "\n";
	//loop through all the shapes in the vector
  for (auto const &shape : m_shapes) {
		//print the properties of the shape so that the shapes are identifiable
    printShape(shape);
  }
  std::cout << "\n";
}

//function prints the shapes with the number of sides equal to the number given as argument
void ShapeSorter::printSide(int side) const {
  std::cout << "SHAPES WITH " << side << " SIDES"
            << "\n";
	//loop through the shapes
  for (auto const &shape : m_shapes) {
		//check if the number of sides is equal to the number given as argument
    if (shape->getSides() == side) {
		  //print the properties of the shapes
      printShape(shape);
    }
  }
  std::cout << "\n";
}

//compare the area of two shapes
bool compareShapesArea(Shape *shape1, Shape *shape2) {
  return shape1->area() < shape2->area();
}

//compare the perimeter of two shapes
bool compareShapesPerimeter(Shape *shape1, Shape *shape2) {
  return shape1->perimeter() < shape2->perimeter();
}
 
//function prints the shapes in area descending order
void ShapeSorter::printAreaDescending() {
  std::cout << "SHAPE AREA"
            << "\n";
	//sort the shapes using the area comparitor
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesArea);
	//loop through the shapes in the newly ordered vector
  for (auto const &shape : m_shapes) {
			//rint the properties of each shape
    printShape(shape);
  }
  std::cout << "\n";
}

//function prints the shapes in perimeter descending order
void ShapeSorter::printPerimeterDescending() {
  std::cout << "SHAPE PERIMETER"
            << "\n";
	//sort the shapes using the area comparitor
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesPerimeter);
	//loop through the shapes in the newly ordered vector
  for (auto const &shape : m_shapes) {
		//print the properties of each shape
    printShape(shape);
  }
  std::cout << "\n";
}
