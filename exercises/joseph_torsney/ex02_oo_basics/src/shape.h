#ifndef SHAPE_H
#define SHAPE_H
 
#include <string>

class Shape {
  public:
    Shape(std::string typeName) {
      type = typeName;
    }

    std::string getSides() {
      return type;
    }

    virtual double getPerimeter() { return 0; }
  
  protected:
    std::string type;
};

#endif