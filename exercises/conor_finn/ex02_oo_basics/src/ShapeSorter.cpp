//
// Created by mkq48465 on 22/09/2021.
//

#include <iostream>
#include <algorithm>
#include "ShapeSorter.h"

void ShapeSorter::printTypes(const std::vector<Shape *>& shapes, const std::string& name) {
    for(Shape * shape: shapes) {
        if(shape->getName() == name) {
            shape->printInfo();
        }
    }
}

void ShapeSorter::printSides(const std::vector<Shape *>& shapes, const int& sides) {
    for(Shape * shape: shapes) {
        if (shape->getNumberOfSides() == sides) {
            shape->printInfo();
        }
    }
}

void ShapeSorter::printOrderedArea(std::vector<Shape *> shapes) {
    std::sort(shapes.begin(), shapes.end(), [] (auto& a, auto& b) { return a->area() > b->area(); });
    for (Shape * shape: shapes) {
        shape->printInfo();
    }
}

void ShapeSorter::printOrderedPerimeter(std::vector<Shape *> shapes) {
    std::sort(shapes.begin(), shapes.end(), [] (auto& a, auto& b) { return a->perimeter() > b->perimeter();});
    for (Shape * shape: shapes) {
        shape->printInfo();
    }
}