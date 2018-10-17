#include <utility>

#include "ShapeSorter.h"

void ShapeSorter::PrintBasedOnType(std::vector<std::reference_wrapper<Shape>> shapes, std::string type)
{
	// Print shapes that have a given type
	for (auto const &shape : shapes)
		if (shape.get().GetType() == type)
            std::cout << shape.get() << std::endl;
}
void ShapeSorter::PrintBasedOnNSides(std::vector<std::reference_wrapper<Shape>> shapes, int numSides)
{
	// Print shapes that have a given number of sides
	for (auto const &shape : shapes)
		if (shape.get().GetNumSides() == numSides)
			std::cout << shape.get() << std::endl;
}
std::vector<std::reference_wrapper<Shape>> ShapeSorter::SortByAreaDesc(std::vector<std::reference_wrapper<Shape>> shapes)
{
	// Create a copy of the shapes vector
	std::vector<std::reference_wrapper<Shape>> copyShapes(std::move(shapes));

	// Create a lambda expression for comparing area values
	auto areaCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetArea() < s1.GetArea() || (s1.GetArea() >= s2.GetArea() && s1.GetArea() < s2.GetArea());
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), areaCompare);

	return copyShapes;
}
std::vector<std::reference_wrapper<Shape>> ShapeSorter::SortByPerimeterDesc(std::vector<std::reference_wrapper<Shape>> shapes)
{
	// Create a copy of the shapes vector
	std::vector<std::reference_wrapper<Shape>> copyShapes(std::move(shapes));

	// Create a lambda expression for sorting by perimeter values
	auto perimCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetPerimeter() < s1.GetPerimeter() || (s1.GetPerimeter() >= s2.GetPerimeter() && s1.GetPerimeter() < s2.GetPerimeter());
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), perimCompare);

	return copyShapes;
}
void ShapeSorter::PrintShapes(std::vector<std::reference_wrapper<Shape>> shapes)
{
	for (auto const &shape : shapes)
        std::cout << shape.get() << std::endl;
}
