#include <iostream>
#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "ShapeSorter.h"

int main() {
    std::vector<Shape *> shapes;
    auto *rect1 = new Rectangle(10.0, 12.0);
    auto *rect2 = new Rectangle(5.0, 20.0);
    auto *squa1 = new Square(6);
    auto *tria1 = new Triangle(6, 4);
    auto *circ1 = new Circle(8);

    shapes.push_back(rect1);
    shapes.push_back(rect2);
    shapes.push_back(squa1);
    shapes.push_back(tria1);
    shapes.push_back(circ1);

    std::cout << "\nPrinting shapes with 4 sides:\n";
    ShapeSorter::printSides(shapes, 4);
    std::cout << "\nPrinting rectangles:\n";
    ShapeSorter::printTypes(shapes, "rectangle");
    std::cout << "\nPrinting shapes ordered by perimeter:\n";
    ShapeSorter::printOrderedPerimeter(shapes);
    std::cout << "\nPrinting Shapes ordered by area:\n";
    ShapeSorter::printOrderedArea(shapes);

    for(Shape *s : shapes) {
        delete s;
    }
}
