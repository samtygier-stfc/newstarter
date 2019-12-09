#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    double side_1;
    double side_2;

    Rectangle();
    Rectangle(double s_1, double s_2);

    double area();
    double perimeter();
};

#endif // RECTANGLE_H
