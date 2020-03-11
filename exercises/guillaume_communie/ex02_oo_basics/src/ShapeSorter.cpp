#include "ShapeSorter.h"

#include <iostream>

void ShapeSorter::printMatchType(std::vector<Shape*> v,
                                                std::string t) {
    for (auto it = v.begin() ; it != v.end() ; it++)
        if ((*it)->getType() == t)
            std::cout << (*it)->print() << std::endl;
}

void ShapeSorter::printMatchSides(std::vector<Shape*> v, int n) {
    for (auto it = v.begin() ; it != v.end() ; it++)
        if ((*it)->getSides() == n)
            std::cout << (*it)->print() << std::endl;
}

