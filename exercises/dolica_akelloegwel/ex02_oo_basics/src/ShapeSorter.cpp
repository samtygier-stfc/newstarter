#include "ShapeSorter.h"

void ShapeSorter::PrintBasedOnType(std::vector<Shape> shapes, std::string type)
{
	// Print shapes that have a given type
	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++) 
	{
		if (it->GetType().compare(type) == 0)
			std::cout << *it << std::endl;
	}
}
void ShapeSorter::PrintBasedOnNSides(std::vector<Shape> shapes, int numSides)
{
	// Print shapes that have a given number of sides
	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++)
	{
		if (it->GetSides() == numSides)
			std::cout << *it << std::endl;
	}
}
void ShapeSorter::SortByAreaDesc(std::vector<Shape> shapes)
{
	// Create a copy of the shapes vector
	std::vector<Shape> copyShapes(shapes);

	// Create a lambda expression for comparing area values
	auto areaCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetArea() < s1.GetArea() || !(s1.GetArea() < s2.GetArea()) && s1.GetArea() < s2.GetArea();
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), areaCompare);

	// Print the elements in the sorted vector
	for (std::vector<Shape>::iterator it = copyShapes.begin(); it != copyShapes.end(); it++)
	{
		std::cout << it->GetArea() << std::endl;
	}
}
void ShapeSorter::SortByPerimeterDesc(std::vector<Shape> shapes)
{
	// Create a copy of the shapes vector
	std::vector<Shape> copyShapes(shapes);

	// Create a lambda expression for sorting by perimeter values
	auto perimCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetPerimeter() < s1.GetPerimeter() || !(s1.GetPerimeter() < s2.GetPerimeter()) && s1.GetPerimeter() < s2.GetPerimeter();
	};

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), perimCompare);

	// Print the sorted vector
	for (std::vector<Shape>::iterator it = copyShapes.begin(); it != copyShapes.end(); it++)
	{
		std::cout << it->GetPerimeter() << std::endl;
	}
}
