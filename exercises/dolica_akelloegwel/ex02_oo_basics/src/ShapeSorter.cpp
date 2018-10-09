#include "ShapeSorter.h"

void ShapeSorter::PrintBasedOnType(std::vector<Shape> shapes, std::string type)
{
	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++) 
	{
		if (it->GetType().compare(type) == 0)
			std::cout << *it << std::endl;
	}
}
void ShapeSorter::PrintBasedOnNSides(std::vector<Shape> shapes, int numSides)
{
	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++)
	{
		if (it->GetSides() == numSides)
			std::cout << *it << std::endl;
	}
}
void ShapeSorter::SortByAreaDesc(std::vector<Shape> shapes)
{
	std::vector<Shape> copyShapes(shapes);

	auto areaCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetArea() < s1.GetArea() || !(s1.GetArea() < s2.GetArea()) && s1.GetArea() < s2.GetArea();
	};

	std::sort(copyShapes.begin(), copyShapes.end(), areaCompare);

	for (std::vector<Shape>::iterator it = copyShapes.begin(); it != copyShapes.end(); it++)
	{
		std::cout << it->GetArea() << std::endl;
	}
}
void ShapeSorter::SortByPerimeterDesc(std::vector<Shape> shapes)
{
	auto perimCompare = [](const Shape &s1, const Shape &s2)
	{
		return s2.GetPerimeter() < s1.GetPerimeter() || !(s1.GetPerimeter() < s2.GetPerimeter()) && s1.GetPerimeter() < s2.GetPerimeter();
	};

	std::sort(shapes.begin(), shapes.end(), perimCompare);

	for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); it++)
	{
		std::cout << it->GetPerimeter() << std::endl;
	}
}
