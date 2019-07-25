/**
 * Skeleton main routine
 */
#include "../inc/Shape.h"
#include "../inc/Square.h"
#include "../inc/Rectangle.h"
#include "../inc/Triangle.h"
#include "../inc/Circle.h"
#include <iostream>

void setup_new_shape(std::vector<Shape*> &shapes)
{
	std::string shape_type;
	double side1;
	double side2;
	std::cout << "Shape: ";
	std::cin >> shape_type;
	std::cout << std::endl;
	if (shape_type == "square") {
		std::cout << "Width size: ";
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

int main(int, char **)
{
	bool exit = false;
	std::string option;
	std::vector<Shape*> shapes;
	while (exit == false) {
		std::cout << "would you like to make a shape? (y/n)   ";
		std::cin >> option;
		std::cout << std::endl;
		if (option == "y") {
			setup_new_shape(shapes);
		}
		else if (option == "n") {
			exit = true;
		}
	}
}