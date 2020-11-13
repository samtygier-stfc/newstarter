/**
 * Solution to Object Oriented C++ Basics exercise
 *
 * Defines some shapes and outputs some information
 *
 */

#include <iostream>
#include <memory>
#include <vector>

#include "shape.h"
#include "shape_sorter.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

int main(int, char **)
{
	shapevec shapes;
	shapes.push_back(std::make_unique<Circle>(3));
	shapes.push_back(std::make_unique<Square>(5));
	shapes.push_back(std::make_unique<Rectangle>(2,4));
	shapes.push_back(std::make_unique<Square>(1.414));
	shapes.push_back(std::make_unique<Triangle>(5,6));

	ShapeSorter shape_sorter(shapes);

	std::cout << "Circles:" << std::endl;
	shape_sorter.PrintShapesByType(std::cout, "circle");
	std::cout << std::endl;
	std::cout << "Rectangles:" << std::endl;
	shape_sorter.PrintShapesByType(std::cout, "rectangle");
	std::cout << std::endl;
	std::cout << "Squares:" << std::endl;
	shape_sorter.PrintShapesByType(std::cout, "square");
	std::cout << std::endl;
	std::cout << "Triangles:" << std::endl;
	shape_sorter.PrintShapesByType(std::cout, "triangle");
	std::cout << std::endl;

	for(int s: {1,3,4})
	{
		std::cout << "Shapes with "<< s <<" sides:" << std::endl;
		shape_sorter.PrintShapesBySides(std::cout, s);
		std::cout << std::endl;
	}

	std::cout << "By perimeter:" << std::endl;
	shape_sorter.PrintShapesByPerimeter(std::cout);
	std::cout << std::endl;

	std::cout << "By area:" << std::endl;
	shape_sorter.PrintShapesByArea(std::cout);
	std::cout << std::endl;
}
