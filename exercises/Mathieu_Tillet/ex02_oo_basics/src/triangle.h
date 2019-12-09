/* Triangle shape */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<cmath>

#include "shape.h"

using namespace std;

class Triangle: public Shape
{
public:
    double height;
    double base;

    Triangle();
    Triangle(double t_height, double t_base);
    ~Triangle(){}

    double area();
    double perimeter();
    ostream& display(ostream &os);
};

#endif // TRIANGLE_H
