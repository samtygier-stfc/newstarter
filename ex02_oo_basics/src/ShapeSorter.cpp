#include "ShapeSorter.h"

#include <algorithm>
#include <iostream>

void ShapeSorter::PrintShapesOfType(const std::vector<std::unique_ptr<Shape>>& shapeVector, const Shape::ShapeType _type)
{
	for (int i = 0; i < shapeVector.size(); ++i) {
		if (shapeVector[i]->getType() == _type) std::cout << i << " is of the selected type" << std::endl;
	}
	std::cout << std::endl;
}

void ShapeSorter::PrintShapesWithNumberOfSides(const std::vector<std::unique_ptr<Shape>>& shapeVector, const unsigned int _sides)
{
	if (_sides < 1 || _sides == 2 || _sides > 4) {
		std::cout << "number of sides not feasible" << std::endl;
		return;
	}

	for (int i = 0; i < shapeVector.size(); ++i) {
		if (shapeVector[i]->getNumberOfSides() == _sides) std::cout << i << " has the selected number of sides" << std::endl;
	}
	std::cout << std::endl;
}

void ShapeSorter::PrintShapesWithDescendingArea(std::vector<std::unique_ptr<Shape>>& shapeVector)
{
	std::sort(std::begin(shapeVector), std::end(shapeVector), [](const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) {
		return a->getArea() > b->getArea();
		});

	std::cout << "descending area:" << std::endl;
	for (auto const& shape : shapeVector)
		std::cout << shape->getArea() << std::endl;

	std::cout << std::endl;
}

void ShapeSorter::PrintShapessWithDescendingPerimeter(std::vector<std::unique_ptr<Shape>>& shapeVector)
{
	std::sort(std::begin(shapeVector), std::end(shapeVector), [](const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) {
		return a->getPerimeter() > b->getPerimeter();
		});

	std::cout << "descending perimeter:" << std::endl;
	for (auto const& shape : shapeVector)
		std::cout << shape->getPerimeter() << std::endl;

	std::cout << std::endl;
}

