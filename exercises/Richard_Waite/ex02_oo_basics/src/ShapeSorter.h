#ifndef ShapeSorter_H
#define ShapeSorter_H

//#include<string> // already included in Shape.h
#include<vector>
#include "Shape.h" // includes iostream

class ShapeSorter {

public:
	// default constructor
	ShapeSorter() {}

	// member functions

	void printShapes(std::vector<Shape*>& in_shapes, std::string in_shapeName) {
		/*
		function to print out shapes that match in_shapeName
		*/

		std::cout << "Printing shapes with type\t" << in_shapeName << std::endl;

		for (std::vector<Shape*>::const_iterator it = in_shapes.begin();
			it != in_shapes.end(); ++it) {

			std::string name = (*it)->getShapeName();

			if (name.compare(in_shapeName)==0) {
				(*it)->print();
			}
			
		}

	} 

};

#endif 