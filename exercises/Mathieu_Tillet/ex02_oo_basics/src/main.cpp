/**
 * Skeleton main routine
 */

#include <iostream>

#include "square.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "shapesorter.h"

using namespace std;

int main(int, char **)
{
    Triangle().display(cout);
    Square(1);
    Circle(1);
    Circle();
    Rectangle(1,2);

    std::vector<Shape*> shapes;
    shapes.push_back(new Triangle(1,1));
    shapes.push_back(new Rectangle(1,1));
    shapes.push_back(new Circle(3.2));
    shapes.push_back(new Square(1.1));

   ShapeSorter().print_by_sides(shapes, 3, cout);
   cout << endl;
   ShapeSorter().print_by_area(shapes, cout);
   cout << endl;
   ShapeSorter().print_by_perimeter(shapes, cout);
   cout << endl;
   ShapeSorter().print_by_type(shapes, "Square", cout);

}
