#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include <vector>
#include <algorithm>

#include "shape.h"

using namespace std;

class ShapeSorter
{
public:
    ShapeSorter();

    static void print_by_sides(vector<Shape*> &vec, int side_nb, ostream &os);
    static void print_by_type(vector<Shape*> &vec, string type, ostream &os);
    static void print_by_area(vector<Shape*> &vec, ostream &os);
    static void print_by_perimeter(vector<Shape*> &vec, ostream &os);

};

#endif // SHAPESORTER_H
