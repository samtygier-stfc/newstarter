#pragma once

#include <functional>
#include "Shape.h"

class ShapeSorter
{
public:
	void PrintBasedOnType(std::vector<std::reference_wrapper<Shape>> shapes, std::string type);
	void PrintBasedOnNSides(std::vector<std::reference_wrapper<Shape>> shapes, int numSides);
	std::vector<std::reference_wrapper<Shape>> SortByAreaDesc(std::vector<std::reference_wrapper<Shape>> shapes);
	std::vector<std::reference_wrapper<Shape>> SortByPerimeterDesc(std::vector<std::reference_wrapper<Shape>> shapes);
	void PrintShapes(std::vector<std::reference_wrapper<Shape>> shapes);

};
