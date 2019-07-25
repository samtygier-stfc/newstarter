#pragma once
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
	void print_shapes_of_given_type(std::vector<Shape*> shapes, std::string type);
	void print_shapes_of_given_number_of_sides(std::vector<Shape*> shapes, std::string n);
	void print_shapes_in_order_of_volume(std::vector<Shape*> shapes);
	void print_shapes_in_order_of_perimiter(std::vector<Shape*> shapes);
};