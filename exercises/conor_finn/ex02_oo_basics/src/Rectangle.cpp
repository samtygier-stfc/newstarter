//
// Created by Conor Finn on 21/09/2021.
//

#include "Rectangle.h"

Rectangle::Rectangle(double s1, double s2) : Shape(4, "rectangle"), m_side1(s1), m_side2(s2){}

double Rectangle::perimeter() const {
    return m_side1 * 2 + m_side2 * 2;
}

double Rectangle::area() const {
    return m_side1 * m_side2;
}