#include "../inc/ShapeSorter.h"
#include <iomanip>
#include <sstream>

void ShapeSorter::print_shapes_of_given_type(std::vector<std::unique_ptr<Shape>> &shapes)
{
	std::string type;
	std::cout << "Shape: ";
	std::cin >> type;
	std::cout << std::endl;
	for (auto &x : shapes) {
		if (x->getShapeName() == type) {
			x->printSelf();
		}
	}
}

void ShapeSorter::print_shapes_of_given_number_of_sides(std::vector<std::unique_ptr<Shape>> &shapes)
{
	int sides;
	std::cout << "Sides: ";
	std::cin >> sides;
	std::cout << std::endl;
	for (auto& x : shapes) {
		if (x->getN_sides() == sides) {
			x->printSelf();
		}
	}
}

void ShapeSorter::print_shapes_in_order_of_volume(std::vector<std::unique_ptr<Shape>> &shapes)
{
	int max_pos = 0;
	std::vector<int> old_max_pos;
	double max_val;
	while (shapes.size() > old_max_pos.size()) {
		max_val = 0;
		for (unsigned int i = 0; i < shapes.size(); i++) {
			if (std::find(old_max_pos.begin(), old_max_pos.end(), i) == old_max_pos.end()) {
				if (shapes[i]->getVolume() > max_val) {
					max_val = shapes[i]->getVolume();
					max_pos = i;
				}
			}
		}
		shapes[max_pos]->printSelf();
		old_max_pos.push_back(max_pos);
	}
}

void ShapeSorter::print_shapes_in_order_of_perimiter(std::vector<std::unique_ptr<Shape>> &shapes)
{
	int max_pos = 0;
	std::vector<int> old_max_pos;
	double max_val;
	while (shapes.size() > old_max_pos.size()) {
		max_val = 0;
		for (unsigned int i = 0; i < shapes.size(); i++) {
			if (std::find(old_max_pos.begin(), old_max_pos.end(), i) == old_max_pos.end()) {
				if (shapes[i]->getPerimeter() > max_val) {
					max_val = shapes[i]->getPerimeter();
					max_pos = i;
				}
			}
		}
		shapes[max_pos]->printSelf();
		old_max_pos.push_back(max_pos);
	}
}
