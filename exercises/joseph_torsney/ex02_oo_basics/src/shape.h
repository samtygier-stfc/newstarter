#ifndef SHAPE_H
#define SHAPE_H
 
#include <string>

class Shape {
  public:
    Shape(std::string t, int s) {
      sides = s;
      type = t;
    }

    int getSides() {
      return sides;
    }

    std::string getType() {
      return type;
    }

    virtual double getArea() { return 0; }

    virtual double getPerimeter() { return 0; }

    std::string toString() {
      return (
        "Type: " + type + 
        ", Sides: " + std::to_string(sides) + 
        ", Area: " + std::to_string(getArea()) + 
        ", Perimeter: " + std::to_string(getPerimeter())
      );
    }

  protected:
    std::string type;
    int sides;
};

#endif