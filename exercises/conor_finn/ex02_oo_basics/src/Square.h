//
// Created by mkq48465 on 22/09/2021.
//

#ifndef SQUARE_H
#define SQUARE_H


#include "Shape.h"

class Square : public Shape {
private:
    double m_sideLength;

public:
    Square(double sideLength);
    double perimeter() const override;
    double area() const override;
};


#endif //SQUARE_H
