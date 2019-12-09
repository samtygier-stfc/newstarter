/* Square shape */

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

using namespace std;

class Square : public Shape
{
public:
    double side_length;

    Square();
    Square(double side);

    double perimeter();
    double area();
    ostream& display(ostream &os);
};

#endif // SQUARE_H
