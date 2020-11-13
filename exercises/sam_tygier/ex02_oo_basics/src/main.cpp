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
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

int main(int, char **)
{
	std::vector<std::unique_ptr<Shape>> shapes;
	shapes.push_back(std::make_unique<Circle>(3));
	shapes.push_back(std::make_unique<Rectangle>(2,4));
	shapes.push_back(std::make_unique<Square>(1.414));
	shapes.push_back(std::make_unique<Triangle>(5,6));
	
	for(auto &s: shapes)
	{
		std::cout << *s << std::endl;
	}
}
