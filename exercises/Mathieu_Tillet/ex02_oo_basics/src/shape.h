#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    std::string shape_type;
    int sides;

    Shape(){}
    virtual ~Shape(){}
    virtual double perimeter()=0;
    virtual double area()=0;
};

#endif // SHAPE_H
