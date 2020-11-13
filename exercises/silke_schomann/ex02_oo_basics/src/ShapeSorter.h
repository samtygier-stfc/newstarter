#ifndef ShapeSorter_h
#define ShapeSorter_h

#include "Shape.h"

#include <vector>
#include <memory>


class ShapeSorter
{
public:
	static void PrintShapesOfType(const std::vector<std::unique_ptr<Shape>>& shapeVector, const Shape::ShapeType _type);
	static void PrintShapesWithNumberOfSides(const std::vector<std::unique_ptr<Shape>>& shapeVector, const unsigned int _sides);
	static void PrintShapesWithDescendingArea(std::vector<std::unique_ptr<Shape>>& shapeVector);
	static void PrintShapessWithDescendingPerimeter(std::vector<std::unique_ptr<Shape>>& shapeVector);

private:
	ShapeSorter() {};
};

#endif