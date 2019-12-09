/*
 *
 */
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
    /* Print shapes corresponding to given number of sides on given output stream */

    static void print_by_type(vector<Shape*> &vec, string type, ostream &os);
    /* Print shapes corresponding to given typename on given output stream */

    static void print_by_area(vector<Shape*> &vec, ostream &os);
    /* Print shapes by descending area on given output stream */

    static void print_by_perimeter(vector<Shape*> &vec, ostream &os);
    /* Print shapes by descending perimeter on given output stream */

};

#endif // SHAPESORTER_H
