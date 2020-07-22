#ifndef SHAPE_H
#define SHAPE_H
 
#include <string>

class Shape {
  public:
    Shape(int s) {
      sides = s;
    }

    int getSides() {
      return sides;
    }
  
  protected:
    int sides;
};

#endif