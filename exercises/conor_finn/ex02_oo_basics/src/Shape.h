//
// Created by Conor Finn on 21/09/2021.
//

#ifndef EX02_OO_BASICS_SHAPE_H
#define EX02_OO_BASICS_SHAPE_H

#include <string>

class Shape {
private:
    const int m_sides;
    const std::string m_name;

public:
    Shape(int sides, std::string name);

    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    int getNumberOfSides() const;
    std::string getName() const;
    void printInfo() const;
};

#endif //EX02_OO_BASICS_SHAPE_H
