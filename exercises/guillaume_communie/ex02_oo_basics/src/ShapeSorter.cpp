#include "ShapeSorter.h"

#include <iostream>
#include <algorithm>

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

void ShapeSorter::printSortedByPerimeter(std::vector<Shape*> v) {
    std::sort(v.begin(), v.end(),
              [](Shape* e1, Shape* e2) -> bool
              {
                  return (e1->getPerimeter() > e2->getPerimeter());
              });

    for (auto it = v.begin() ; it != v.end() ; it++)
        std::cout << (*it)->print() << std::endl;
}

void ShapeSorter::printSortedByArea(std::vector<Shape*> v) {
    std::sort(v.begin(), v.end(),
              [](Shape* e1, Shape* e2) -> bool
              {
                  return (e1->getArea() > e2->getArea());
              });

    for (auto it = v.begin() ; it != v.end() ; it++)
        std::cout << (*it)->print() << std::endl;
}

