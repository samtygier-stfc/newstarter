/* Virtual class representing a geometric shape */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <ostream>

using namespace std;

class Shape
{
public:
    std::string shape_type;
    int sides;

    Shape(){}
    virtual ~Shape(){}
    virtual double perimeter()=0;
    virtual double area()=0;
    virtual ostream& display(ostream &os)=0;
};

ostream& operator<<(ostream &os, Shape &sh);

#endif // SHAPE_H
