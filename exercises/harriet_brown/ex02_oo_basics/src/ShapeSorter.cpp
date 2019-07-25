#include "../inc/ShapeSorter.h"
#include <iomanip>
#include <sstream>

void ShapeSorter::print_shapes_of_given_type(std::vector<Shape*> shapes, std::string type)
{
	Shape* shape;
	for (int i = 0; i < shapes.size(); i++) {
		shape = shapes[i];
		if (shape->getShape() == type) {
			std::cout << "poition: " << i << "." << std::setw(12) << "Perimiter: " << shape->getPerimeter() << std::setw(12) << "Volume: " << shape->getVolume() << std::endl;
		}
	}
}

void ShapeSorter::print_shapes_of_given_number_of_sides(std::vector<Shape*> shapes, std::string n)
{
	int sides;
	std::istringstream iss(n);
	iss >> sides;
	if (iss.fail()) {
		return;
	}
	Shape* shape;
	for (int i = 0; i < shapes.size(); i++) {
		shape = shapes[i];
		if (shape->getN_sides() == sides) {
			std::cout << "poition: " << i << "." << std::setw(15) << "Perimiter: " << shape->getPerimeter() << std::setw(15) << "Volume: " << shape->getVolume() << std::endl;
		}
	}
}

void ShapeSorter::print_shapes_in_order_of_volume(std::vector<Shape*> shapes)
{
	Shape* shape;
	int max_pos;
	double max_val;
	while (shapes.size() > 0) {
		max_val = 0;
		for (int i = 0; i < shapes.size(); i++) {
			shape = shapes[i];
			if (shape->getVolume() > max_val) {
				max_val = shape->getVolume();
				max_pos = i;
			}
		}
		std::cout << std::setw(12) << "poition: " << max_pos << "." << std::setw(15) << "Shape: " << shapes[max_pos]->getShape() << std::setw(15) 
			<< "Volume: " << shapes[max_pos]->getVolume() << std::endl;
		shapes.erase(shapes.begin()+max_pos);
	}
}

void ShapeSorter::print_shapes_in_order_of_perimiter(std::vector<Shape*> shapes)
{
	Shape* shape;
	int max_pos;
	double max_val;
	while (shapes.size() > 0) {
		max_val = 0;
		for (int i = 0; i < shapes.size(); i++) {
			shape = shapes[i];
			if (shape->getPerimeter() > max_val) {
				max_val = shape->getPerimeter();
				max_pos = i;
			}
		}
		std::cout << std::setw(12) << "poition: " << max_pos << "." << std::setw(15) << "Shape: " << shapes[max_pos]->getShape() << std::setw(15)
			<< "Perimeter: " << shapes[max_pos]->getPerimeter() << std::endl;
		shapes.erase(shapes.begin() + max_pos);
	}
}
