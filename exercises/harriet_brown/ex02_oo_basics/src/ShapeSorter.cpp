#include "../inc/ShapeSorter.h"
#include <iomanip>
#include <sstream>

void ShapeSorter::print_shapes_of_given_type(std::vector<Shape*> shapes)
{
	std::string type;
	std::cout << "Shape: ";
	std::cin >> type;
	std::cout << std::endl;
	Shape* shape;
	for (unsigned int i = 0; i < shapes.size(); i++) {
		shape = shapes[i];
		if (shape->getShape() == type) {
			shape->printSelf();
		}
	}
}

void ShapeSorter::print_shapes_of_given_number_of_sides(std::vector<Shape*> shapes)
{
	int sides;
	std::cout << "Sides: ";
	std::cin >> sides;
	std::cout << std::endl;
	Shape* shape;
	for (unsigned int i = 0; i < shapes.size(); i++) {
		shape = shapes[i];
		if (shape->getN_sides() == sides) {
			shape->printSelf();
		}
	}
}

void ShapeSorter::print_shapes_in_order_of_volume(std::vector<Shape*> shapes)
{
	Shape* shape;
	int max_pos = 0;
	double max_val;
	while (shapes.size() > 0) {
		max_val = 0;
		for (unsigned int i = 0; i < shapes.size(); i++) {
			shape = shapes[i];
			if (shape->getVolume() > max_val) {
				max_val = shape->getVolume();
				max_pos = i;
			}
		}
		shapes[max_pos]->printSelf();
		shapes.erase(shapes.begin()+max_pos);
	}
}

void ShapeSorter::print_shapes_in_order_of_perimiter(std::vector<Shape*> shapes)
{
	Shape* shape;
	int max_pos = 0;
	double max_val;
	while (shapes.size() > 0) {
		max_val = 0;
		for (unsigned int i = 0; i < shapes.size(); i++) {
			shape = shapes[i];
			if (shape->getPerimeter() > max_val) {
				max_val = shape->getPerimeter();
				max_pos = i;
			}
		}
		shapes[max_pos]->printSelf();
		shapes.erase(shapes.begin() + max_pos);
	}
}
