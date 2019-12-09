/**
 * Skeleton main routine
 */

#include <vector>
#include <iostream>

#include "square.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"

using namespace std;

int main(int, char **)
{
    cout << Triangle(1,1);
    cout << Triangle();
    cout << Square();
    cout << Square(1);
    cout << Circle(1);
    cout << Circle();
    cout << Rectangle(1,2);
    cout << Rectangle();

    std::vector<Shape*> shapes;
    shapes.push_back(new Triangle(1,1));
    shapes.push_back(new Rectangle(1,1));
    shapes.push_back(new Circle(3.2));
    shapes.push_back(new Square(1.1));

}
