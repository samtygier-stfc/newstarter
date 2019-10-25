#include"Shape.h"

void Shape::print() {
	// std::ostream& out
	// -> is to access members of object to which pointer points...
	std::cout << "Type: " << this->getShapeName() << "\t" <<
		"Area: " << this->calcArea() << "\t" <<
		"Perimiter: " << this->calcPerimiter() << std::endl;
}