#include "ShapeSorter.h"

// Construct the object if no arguments are given
ShapeSorter::ShapeSorter() : m_shapes(0) {}

/* Construct the object to organise different shapes
*
* @param shapes A vector of different shapes
*
*/
ShapeSorter::ShapeSorter(std::vector<Shape *> shapes) : m_shapes(shapes) {}

/* Prints the properties of a shape
*
* @param A pointer to a shape
*
*/
void printShape(Shape *shape) {
  // Prints the properties of the shapes so that they are identifiable
  std::cout << "The shape " << shape->getType() << " has " << shape->getSides()
            << " sides, a perimeter of " << shape->perimeter() << " and area "
            << shape->area() << "\n";
}

/*Prints the types of all of the shapes
*
* @param type Type of shape the user wants to be printed
*
*/
void ShapeSorter::printType(std::string type) const {
  std::cout << "TYPES"
            << "\n";
	// Loop through all the shapes in the vector
  for (auto const &shape : m_shapes) {
			if (shape->getType() == type) {
					printShape(shape);
			}
  }
  std::cout << "\n";
}

/* Prints the shapes with the number of sides equal to the number given as argument
*
* @param side The side number of the shpes the user wants to print 
*
*/
void ShapeSorter::printSide(int side) const {
  std::cout << "SHAPES WITH " << side << " SIDES"
            << "\n";
	// Loop through the shapes
  for (auto const &shape : m_shapes) {
		// Check if the number of sides is equal to the number given as argument
    if (shape->getSides() == side) {
		  // Print the properties of the shapes
      printShape(shape);
    }
  }
  std::cout << "\n";
}

/* Compare the area of two shapes
*
* @param shape1 pointer to a shape
* @param shape2 pointer to another shape with which to compare
*@return A bool determining if shape1 was smaller in area than shape 2
*
*/
bool compareShapesArea(Shape *shape1, Shape *shape2) {
  return shape1->area() < shape2->area();
}

/* Compare the perimeter of two shapes
*
* @param shape1 pointer to a shape
* @param shape2 pointer to another shape with which to compare
*@return A bool determining if shape1 was smaller in perimeter than shape 2
*
*/
bool compareShapesPerimeter(Shape *shape1, Shape *shape2) {
  return shape1->perimeter() < shape2->perimeter();
}
 
// Prints the shapes in area descending order
void ShapeSorter::printAreaDescending() {
  std::cout << "SHAPE AREA"
            << "\n";
	// Sort the shapes using the area comparitor
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesArea);
	// Loop through the shapes in the newly ordered vector
  for (auto const &shape : m_shapes) {
			// Print the properties of each shape
    printShape(shape);
  }
  std::cout << "\n";
}

// Prints the shapes in perimeter descending order
void ShapeSorter::printPerimeterDescending() {
  std::cout << "SHAPE PERIMETER"
            << "\n";
	// Sort the shapes using the area comparitor
  std::sort(m_shapes.begin(), m_shapes.end(), compareShapesPerimeter);
	// Loop through the shapes in the newly ordered vector
  for (auto const &shape : m_shapes) {
		// Print the properties of each shape
    printShape(shape);
  }
  std::cout << "\n";
}
