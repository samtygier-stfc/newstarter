#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "Shape.h"

class ShapeSorter
{
public:
	void PrintBasedOnType(std::vector<Shape> shapes, std::string type);
	void PrintBasedOnNSides(std::vector<Shape> shapes, int numSides);
	void SortByAreaDesc(std::vector<Shape> shapes);
	void SortByPerimeterDesc(std::vector<Shape> shapes);

};