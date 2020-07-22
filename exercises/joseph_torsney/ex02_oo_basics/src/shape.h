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
  
  protected:
    std::string type;
};

#endif