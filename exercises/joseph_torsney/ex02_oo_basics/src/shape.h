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
  
  protected:
    std::string type;
    int sides;
};

#endif