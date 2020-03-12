#include "ShapeSorter.h"

#include <iostream>
#include <algorithm>

void ShapeSorter::printMatchType(const std::vector<Shape*> &v,
                                 const std::string &t) {
    std::vector<Shape*> match(v.size());
    auto it = std::copy_if(v.begin(), v.end(), match.begin(),
                           [] (Shape *s) -> bool
                           {
                               return s->getType() == "circle";
                           });
    match.resize(std::distance(match.begin(), it));

    printVector(match);
}

void ShapeSorter::printMatchSides(const std::vector<Shape*> &v, int n) {
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

    printVector(v);
}

void ShapeSorter::printSortedByArea(std::vector<Shape*> v) {
    std::sort(v.begin(), v.end(),
              [](Shape* e1, Shape* e2) -> bool
              {
                  return (e1->getArea() > e2->getArea());
              });

    printVector(v);
}

void ShapeSorter::printVector(const std::vector<Shape*> &v) {
    for (auto e : v)
        std::cout << e->print() << std::endl;
}

