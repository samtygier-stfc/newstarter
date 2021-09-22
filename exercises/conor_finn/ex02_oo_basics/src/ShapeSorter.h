//
// Created by mkq48465 on 22/09/2021.
//

#ifndef SHAPESORTER_H
#define SHAPESORTER_H


#include <vector>
#include "Shape.h"

class ShapeSorter {
public:
    static void printTypes(const std::vector<Shape *>& shapes, const std::string& name);
    static void printSides(const std::vector<Shape *>& shapes, const int& sides);
    static void printOrderedArea(std::vector<Shape *> shapes);
    static void printOrderedPerimeter(std::vector<Shape *> shapes);
};


#endif //SHAPESORTER_H
