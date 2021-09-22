//
// Created by mkq48465 on 22/09/2021.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double const m_base;
    double const m_height;

public:
    Triangle(double base, double height);
    double perimeter() const override;
    double area() const override;
};


#endif //TRIANGLE_H
