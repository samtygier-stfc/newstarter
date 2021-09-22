//
// Created by Conor Finn on 21/09/2021.
//

#include "Shape.h"

#include <utility>
#include <iostream>

Shape::Shape(int sides, std::string name): m_sides(sides), m_name(name) {}

int Shape::getNumberOfSides() const { return m_sides;}

std::string Shape::getName() const { return m_name;}

void Shape::printInfo() const {
    std::cout << "This is a " << getName() << ". With a perimeter of " << perimeter() << " and an area of " << area()
              << ".\n";
}