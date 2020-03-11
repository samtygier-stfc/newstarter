/**
 * Skeleton main routine
 */

#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"

#include <vector>
#include <iostream>

int main(int, char **) {
    Square s1(10), s2(14), s3(18);
    Rectangle r1(10, 20), r2(14, 8);
    Circle c1(5), c2(8), c3(35);
    Triangle t1(10, 8), t2(21, 2), t3(7, 18);

    std::vector<Shape*> v;
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(&s3);
    v.push_back(&r1);
    v.push_back(&r2);
    v.push_back(&c1);
    v.push_back(&c2);
    v.push_back(&c3);
    v.push_back(&t1);
    v.push_back(&t2);
    v.push_back(&t3);

    std::cout << "Elements that correspond to type 'circle':" << std::endl;
    ShapeSorter::printMatchType(v, "circle");
    std::cout << std::endl;

    std::cout << "Elements that have 3 sides:" << std::endl;
    ShapeSorter::printMatchSides(v, 3);
    std::cout << std::endl;

    std::cout << "Elements sorted by decreasing perimeter value:" << std::endl;
    ShapeSorter::printSortedByPerimeter(v);
    std::cout << std::endl;

    std::cout << "Elements sorted by decreasing area value:" << std::endl;
    ShapeSorter::printSortedByArea(v);
}

