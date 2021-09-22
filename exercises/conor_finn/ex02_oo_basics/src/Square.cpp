//
// Created by mkq48465 on 22/09/2021.
//

#include "Square.h"

Square::Square(double sideLength) : Shape(4, "square"), m_sideLength(sideLength){}

double Square::perimeter() const {
    return m_sideLength * 4;
}

double Square::area() const {
    return pow(m_sideLength, 2);
}