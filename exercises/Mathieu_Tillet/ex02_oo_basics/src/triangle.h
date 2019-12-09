#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<math.h>

#include "shape.h"

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

#endif // TRIANGLE_H
