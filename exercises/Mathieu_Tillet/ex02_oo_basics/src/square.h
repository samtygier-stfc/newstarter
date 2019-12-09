#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
public:
    double side_length;

    Square();
    Square(double side);

    double perimeter();
    double area();
};

#endif // SQUARE_H
