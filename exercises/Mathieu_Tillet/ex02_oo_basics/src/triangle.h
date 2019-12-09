#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<math.h>
#include<ostream>

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
};
ostream& operator<<(ostream &os, const Triangle &t);

#endif // TRIANGLE_H
