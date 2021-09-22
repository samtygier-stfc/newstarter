//
// Created by Conor Finn on 21/09/2021.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    const double m_side1;
    const double m_side2;

public:
    Rectangle(int s1, int s2);
    double perimeter() const override;
    double area() const override;
};


#endif //RECTANGLE_H
