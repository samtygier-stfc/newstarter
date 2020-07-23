#pragma once

#include <string>

class Shape {
  public:
    Shape(std::string t, int s);

    int getSides();

    std::string getType();

    virtual double getArea() { return 0; }

    virtual double getPerimeter() { return 0; }

    std::string toString();

  protected:
    std::string type;
    int sides;
};
