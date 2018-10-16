#include "ShapeSorter.h"

void ShapeSorter::PrintBasedOnType(std::vector<std::reference_wrapper<Shape>> shapes, std::string type)
{
	// Print shapes that have a given type
	for (int i = 0; i < shapes.size(); i++)
		if (shapes[i].get().GetType().compare(type) == 0)
			std::cout << shapes[i].get() << std::endl;
}
void ShapeSorter::PrintBasedOnNSides(std::vector<std::reference_wrapper<Shape>> shapes, int numSides)
{
	// Print shapes that have a given number of sides
	for (int i = 0; i < shapes.size(); i++)
		if (shapes[i].get().GetNumSides() == numSides)
			std::cout << shapes[i].get() << std::endl;
}
std::vector<std::reference_wrapper<Shape>> ShapeSorter::SortByAreaDesc(std::vector<std::reference_wrapper<Shape>> shapes)
{
	// Create a copy of the shapes vector
	std::vector<std::reference_wrapper<Shape>> copyShapes(shapes);

	// Create a lambda expression for comparing area values
	auto areaCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetArea() < s1.GetArea() || !(s1.GetArea() < s2.GetArea()) && s1.GetArea() < s2.GetArea();
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), areaCompare);

	return copyShapes;
}
std::vector<std::reference_wrapper<Shape>> ShapeSorter::SortByPerimeterDesc(std::vector<std::reference_wrapper<Shape>> shapes)
{
	// Create a copy of the shapes vector
	std::vector<std::reference_wrapper<Shape>> copyShapes(shapes);

	// Create a lambda expression for sorting by perimeter values
	auto perimCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetPerimeter() < s1.GetPerimeter() || !(s1.GetPerimeter() < s2.GetPerimeter()) && s1.GetPerimeter() < s2.GetPerimeter();
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), perimCompare);

	return copyShapes;
}
void ShapeSorter::PrintShapes(std::vector<std::reference_wrapper<Shape>> shapes)
{
	for (int i = 0; i < shapes.size(); i++)
		std::cout << shapes[i].get() << std::endl;
}
