//
// Created by mkq48465 on 22/09/2021.
//

#include "Circle.h"

Circle::Circle(double radius) : Shape(1, "circle"), m_radius(radius){}

double Circle::perimeter() const {
    return 2 * M_PI * m_radius;
}

double Circle::area() const {
    return M_PI * pow(m_radius, 2);
}