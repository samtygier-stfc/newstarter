#ifndef ShapeSorter_H
#define ShapeSorter_H

//#include<string> // already included in Shape.h
#include<vector>
#include<algorithm>
#include "Shape.h" // includes iostream

class ShapeSorter {

public:
	// default constructor
	ShapeSorter() {}

	// member functions

	void printShapesType(std::vector<Shape*>& in_shapes, std::string in_shapeName) {
		/*
		function to print out shapes that match in_shapeName
		*/

		std::cout << std::endl << "Printing shapes of type " << in_shapeName << std::endl;

		for (std::vector<Shape*>::const_iterator it = in_shapes.begin();
			it != in_shapes.end(); ++it) {

			if (in_shapeName.compare((*it)->getShapeName()) ==0) {
				(*it)->print();
			}
			
		}

	} 

	void printShapesNsides(std::vector<Shape*>& in_shapes, int n) {
		/*
		function to print out shapes that match in_shapeName
		*/

		std::cout << std::endl << "Printing shapes with " << n << " sides" << std::endl;


		for (std::vector<Shape*>::const_iterator it = in_shapes.begin();
			it != in_shapes.end(); ++it) {

			if (n == (*it)->getNsides()) {
				(*it)->print();
			}

		}

	}

	void printShapesArea(std::vector<Shape*>& in_shapes) {
		/*
		function to print out shapes that match in_shapeName
		*/

		std::cout << std::endl << "Printing shapes in descending order of area" << std::endl;

		// sort the vector (in descending order)
		std::sort(in_shapes.begin(), in_shapes.end(), 
			[](const Shape* s1, const Shape* s2) { return s1->calcArea() > s2->calcArea(); });

		for (std::vector<Shape*>::const_iterator it = in_shapes.begin();
			it != in_shapes.end(); ++it) {

			(*it)->print();
		}

	}

	void printShapesPerimiter(std::vector<Shape*>& in_shapes) {
		/*
		function to print out shapes that match in_shapeName
		*/

		std::cout << std::endl << "Printing shapes in descending order of perimiter" << std::endl;

		// sort the vector (in descending order)
		std::sort(in_shapes.begin(), in_shapes.end(),
			[](const Shape* s1, const Shape* s2) { return s1->calcPerimiter() > s2->calcPerimiter(); });

		for (std::vector<Shape*>::const_iterator it = in_shapes.begin();
			it != in_shapes.end(); ++it) {

			(*it)->print();
		}

	}

};

#endif 