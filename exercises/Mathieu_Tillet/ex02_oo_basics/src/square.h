#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include<ostream>

using namespace std;

class Square : public Shape
{
public:
    double side_length;

    Square();
    Square(double side);

    double perimeter();
    double area();
};
ostream& operator<<(ostream &os, const Square &s);

#endif // SQUARE_H
