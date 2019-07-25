/**
 * Skeleton main routine
 */
#include <iostream>
#include <vector>
#include <string>
#include "../inc/ShapeSorter.h"

void setup_new_shape(std::vector<Shape*> &shapes)
{
	std::string shape_type;
	double side1;
	double side2;
	std::cout << "Shape: ";
	std::cin >> shape_type;
	std::cout << std::endl;
	if (shape_type == "square") {
		std::cout << "Side size: ";
		std::cin >> side1;
		std::cout << std::endl;
		shapes.push_back(new Square(side1));
	}
	else if (shape_type == "rectangle") {
		std::cout << "Width size: ";
		std::cin >> side1;
		std::cout << std::endl;
		std::cout << "Height size: ";
		std::cin >> side2;
		std::cout << std::endl;
		shapes.push_back(new Rectangle(side1, side2));
	}
	else if (shape_type == "triangle") {
		std::cout << "Base size: ";
		std::cin >> side1;
		std::cout << std::endl;
		std::cout << "Height size: ";
		std::cin >> side2;
		std::cout << std::endl;
		shapes.push_back(new Triangle(side1, side2));
	}
	else if (shape_type == "circle") {
		std::cout << "Radius size: ";
		std::cin >> side1;
		std::cout << std::endl;
		shapes.push_back(new Circle(side1));
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

int main(int, char **)
{
	bool exit = false;
	std::string option;
	ShapeSorter sorter;
	std::vector<Shape*> shapes;
	while (exit == false) {
		print_option_text();
		std::cin >> option;
		std::cout << std::endl;
		if (option == "1") {
			setup_new_shape(shapes);
		}
		else if (option == "2") {
			std::cout << "Shape: ";
			std::cin >> option;
			std::cout << std::endl;
			sorter.print_shapes_of_given_type(shapes, option);
		}
		else if (option == "3") {
			std::cout << "Sides: ";
			std::cin >> option;
			std::cout << std::endl;
			sorter.print_shapes_of_given_number_of_sides(shapes, option);
		}
		else if (option == "4") {
			sorter.print_shapes_in_order_of_volume(shapes);
		}
		else if (option == "5") {
			sorter.print_shapes_in_order_of_perimiter(shapes);
		}
		else if (option == "0") {
			exit = true;
		}
	}
}