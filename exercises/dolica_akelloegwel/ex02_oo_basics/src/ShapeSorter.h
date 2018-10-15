#pragma once



#include <functional>
#include "Shape.h"

class ShapeSorter
{
public:
	void PrintBasedOnType(std::vector<std::reference_wrapper<Shape>> shapes, std::string type);
	void PrintBasedOnNSides(std::vector<std::reference_wrapper<Shape>> shapes, int numSides);
	void SortByAreaDesc(std::vector<std::reference_wrapper<Shape>> shapes);
	void SortByPerimeterDesc(std::vector<std::reference_wrapper<Shape>> shapes);

};
