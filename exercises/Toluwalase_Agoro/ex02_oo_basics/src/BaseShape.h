#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>


class BaseShape {
  public:
    int m_numberOfSides{0};
    std::string m_type;
    double m_area{0.0};
    double m_perimeter{ 0.0 };
    virtual double calculateArea()=0;
    virtual double calculatePerimeter() = 0;
    BaseShape(int numberOfSides, std::string type) : m_numberOfSides{ numberOfSides }, m_type{ type } {
    }
};
