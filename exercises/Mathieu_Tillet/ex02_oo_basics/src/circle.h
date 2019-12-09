#ifndef CIRCLE_H
#define CIRCLE_H

#include<cmath>

#include "shape.h"

class Circle : public Shape
{
public:
    double radius;

    Circle();
    Circle(double r);

    double area();
    double perimeter();
};

#endif // CIRCLE_H
