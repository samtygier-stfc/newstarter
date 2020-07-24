#pragma once

#include <string>

class Shape {
  public:
    Shape(std::string t, int s);

    int getSides();

    std::string getType();

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    std::string toString();

  protected:
    const std::string m_type;
    const int m_sides;
};
