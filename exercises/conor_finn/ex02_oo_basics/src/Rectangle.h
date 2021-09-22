//
// Created by Conor Finn on 21/09/2021.
//

#ifndef EX02_OO_BASICS_RECTANGLE_H
#define EX02_OO_BASICS_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    const int m_side1;
    const int m_side2;

public:
    Rectangle(int s1, int s2);
    double perimeter() const override;
    double area() const override;
};


#endif //EX02_OO_BASICS_RECTANGLE_H
