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

    ShapeSorter::printMatchType(v, "circle");
    ShapeSorter::printMatchSides(v, 3);
}

