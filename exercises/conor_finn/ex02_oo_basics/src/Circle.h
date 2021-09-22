//
// Created by mkq48465 on 22/09/2021.
//

#ifndef CIRCLE_H
#define CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
private:
    double m_radius;

public:
    Circle(double radius);
    double perimeter() const override;
    double area() const override;
};


#endif //CIRCLE_H
