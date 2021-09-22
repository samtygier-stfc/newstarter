//
// Created by mkq48465 on 22/09/2021.
//

#include "Triangle.h"

Triangle::Triangle(double base, double height) : Shape(3, "triangle"), m_base(base), m_height(height) {}

double Triangle::perimeter() const {
    return m_base + 2 * sqrt(pow(m_height, 2) + pow(m_base, 2) / 4);
}

double Triangle::area() const {
    return (m_base * m_height) / 2;
}