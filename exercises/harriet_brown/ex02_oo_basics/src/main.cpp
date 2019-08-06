/**
 * Skeleton main routine
 */
#include <iostream>
#include <vector>
#include <string>
#include "../inc/ShapeSorter.h"
#include "../inc/getInput.h"


void setup_new_shape(std::vector<std::unique_ptr<Shape>> &shapes)
{
	std::string shape_type;
	double side1;
	double side2;
	shape_type = getInput<std::string>("Shape: ");
	if (shape_type == "square") {
		side1 = getInput<double>("Side size: ");
		shapes.push_back(std::make_unique <Square>(side1));
	}
	else if (shape_type == "rectangle") {
		side1 = getInput<double>("Width size: ");
		side2 = getInput<double>("Height size: ");
		shapes.push_back(std::make_unique <Rectangle>(side1, side2));
	}
	else if (shape_type == "triangle") {
		side1 = getInput<double>("Base size: ");
		side2 = getInput<double>("Height size: ");
		shapes.push_back(std::make_unique <Triangle>(side1, side2));
	}
	else if (shape_type == "circle") {
		side1 = getInput<double>("Radius size: ");
		shapes.push_back(std::make_unique <Circle>(side1));
	}
}

void print_option_text()
{
	std::cout << std::endl << std::endl;
	std::cout << "----select options----" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1.) New shape" << std::endl;
	std::cout << "2.) List by shape" << std::endl;
	std::cout << "3.) List by number of sides" << std::endl;
	std::cout << "4.) List in order of volume" << std::endl;
	std::cout << "5.) List in order of perimeter" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "0.) exit" << std::endl;
	std::cout << std::endl << std::endl;
}

int main()
{
	bool exit = false;
	int option;
	ShapeSorter sorter;
	std::vector<std::unique_ptr<Shape>> shapes;
	while (exit == false) {
		print_option_text();
		option = getInput<int>("option: ");
		if (option == 1) {setup_new_shape(shapes);}
		else if (option == 2) {sorter.print_shapes_of_given_type(shapes);}
		else if (option == 3) {sorter.print_shapes_of_given_number_of_sides(shapes);}
		else if (option == 4) {sorter.print_shapes_in_order_of_volume(shapes);}
		else if (option == 5) {sorter.print_shapes_in_order_of_perimiter(shapes);}
		else if (option == 0) {exit = true;}
	}
	return 0;
}
