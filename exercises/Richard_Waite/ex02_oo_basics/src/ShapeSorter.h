#ifndef ShapeSorter_H
#define ShapeSorter_H

#include "Shape.h" // includes iostream
#include<vector>
#include<algorithm>

class ShapeSorter {

public:
	// default constructor
	ShapeSorter() {}

	// member functions
	void printShapesType(std::vector<Shape*>& in_shapes, std::string in_shapeName) ;
	void printShapesNsides(std::vector<Shape*>& in_shapes, int n) ;
	void printShapesArea(std::vector<Shape*>& in_shapes);
	void printShapesPerimiter(std::vector<Shape*>& in_shapes);

};

#endif 