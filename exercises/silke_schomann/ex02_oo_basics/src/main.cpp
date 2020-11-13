#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

#include <iostream>
#include <memory>
#include <vector>


int main(int, char **)
{
	std::vector<std::unique_ptr<Shape>> shapeCollection;

	shapeCollection.emplace_back(std::make_unique<Circle>(2));
	shapeCollection.emplace_back(std::make_unique<Square>(1));
	shapeCollection.emplace_back(std::make_unique<Triangle>(2, 3));
	shapeCollection.emplace_back(std::make_unique<Rectangle>(5, 2));
	shapeCollection.emplace_back(std::make_unique<Rectangle>(1, 3));
	shapeCollection.emplace_back(std::make_unique<Triangle>(4, 1));
	shapeCollection.emplace_back(std::make_unique<Circle>(4));
	shapeCollection.emplace_back(std::make_unique<Square>(4));
	shapeCollection.emplace_back(std::make_unique<Rectangle>(2, 3));
	shapeCollection.emplace_back(std::make_unique<Triangle>(2, 1));
	shapeCollection.emplace_back(std::make_unique<Circle>(3));
	shapeCollection.emplace_back(std::make_unique<Circle>(5));

	ShapeSorter::PrintShapesOfType(shapeCollection, Shape::ShapeType::Rectangle);
	ShapeSorter::PrintShapesWithNumberOfSides(shapeCollection, 2);
	ShapeSorter::PrintShapesWithNumberOfSides(shapeCollection, 3);
	ShapeSorter::PrintShapesWithDescendingArea(shapeCollection);
	ShapeSorter::PrintShapessWithDescendingPerimeter(shapeCollection);
}