#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"


class ShapeSorter
{
private:
public:
	void print_shapes_of_given_type(std::vector<std::unique_ptr<Shape>> &shapes);
	void print_shapes_of_given_number_of_sides(std::vector<std::unique_ptr<Shape>> &shapes);
	void print_shapes_in_order_of_volume(std::vector<std::unique_ptr<Shape>> &shapes);
	void print_shapes_in_order_of_perimiter(std::vector<std::unique_ptr<Shape>> &shapes);
};

#endif